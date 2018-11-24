#include "Game.h"
#include "FinishLine.h"



Game::Game() :_collision(0, 500, 1000, 200), _ptrWindow(std::make_shared<sf::RenderWindow>(sf::VideoMode(1000, 500), "Eagle", sf::Style::Close)), _ptrMissiles(std::make_shared<std::vector<std::unique_ptr<Missile>>>()), _textureContainer(std::make_shared<TextureContainer>())
{
	LoadTexture();
	SetUp();
}

Game::~Game()
{

}

void Game::Run()
{
	sf::Clock clock;
	while (_ptrWindow->isOpen())
	{
		const sf::Time time = clock.restart();
		if (!_eventHandler.IsGamePaused())
		{
			HandleInput();
			Update(time);
			Render();
			GenerateRaptor();
		}
		else
		{
			HandleInput();
			RenderMenu();
		}
	}
}

void Game::KeyPressed(const sf::Event::KeyEvent& event)
{
	_eventHandler.AddEvent(event.code);
	if (_eventHandler.IsGamePaused())
		_eventHandler.MakeMenuEvent();
	else
		_eventHandler.MakeEvent();
}

void Game::KeyRelesed(const sf::Event::KeyEvent& event)
{
	_eventHandler.RelaseEvent(event.code);
	if (_eventHandler.IsGamePaused())
		_eventHandler.MakeMenuEvent();
	else
		_eventHandler.MakeEvent();
}

void Game::Update(const sf::Time deltaTime)
{
	std::vector<std::vector<std::unique_ptr<Missile>>::iterator>toDelate;
	std::vector<std::vector<std::unique_ptr<Raptor>>::iterator>toDelate1;
	_ptrEagle->Update(deltaTime);
	_ai.EagleChanger(*_ptrEagle);
	for (auto&i : _vectorRaptor)
	{
		i->Update(deltaTime);
		_ai.RaptorChanger(*i);
		if (_collision.FinishLine(*i))
		{
			Sleep(1000);
			_ptrMenu->SetVisibleExit(true);
			_ptrMenu->LoadResult(_ptrCounter->GetPoints());
			_eventHandler.SetGamePaused(true);

		}

	}
	for (auto &i : *_ptrMissiles)
		i->Update(deltaTime);
	DestroyMissileRaptor();

	for (auto &i : _vectorAnimation)
		i->Update(deltaTime);


}

void Game::Render()
{
	std::vector<std::vector<std::unique_ptr<Missile>>::iterator>toDelate;
	std::vector<std::vector<std::unique_ptr<Raptor>>::iterator>toDelate1;
	std::vector<std::vector<std::unique_ptr<Animation>>::iterator>toDelate2;
	_ptrWindow->clear();
	for (auto& i : _baseObject)
		_ptrWindow->draw(*i);
	for (auto& i : _vectorRaptor)
	{
		_ptrWindow->draw(*i);
	}

	for (auto& i : *_ptrMissiles)
	{
		_ptrWindow->draw(*i);
		if (_collision.Right(*i))
		{
			const auto it = std::find(_ptrMissiles->begin(), _ptrMissiles->end(), i);
			if (it != _ptrMissiles->end())
				toDelate.push_back(it);
		}
	}
	for (auto&i : _vectorAnimation)
	{
		if (i->IsFinish())
		{
			const auto it = std::find(_vectorAnimation.begin(), _vectorAnimation.end(), i);
			if (it != _vectorAnimation.end())
				toDelate2.push_back(it);
			continue;
		}
		_ptrWindow->draw(*i);
	}

	for (const auto i : toDelate)
		_ptrMissiles->erase(i);
	for (const auto i : toDelate1)
		_vectorRaptor.erase(i);

	for (const auto&i : toDelate2)
		_vectorAnimation.erase(i);

	_ptrWindow->draw(*_ptrEagle);
	_ptrWindow->draw(*_ptrCounter);
	_ptrWindow->display();
}

void Game::HandleInput()
{
	sf::Event event{};
	while (_ptrWindow->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
			KeyPressed(event.key);
		else if (event.type == sf::Event::KeyReleased)
			KeyRelesed(event.key);
		else if (event.type == sf::Event::Closed)
			_ptrWindow->close();
	}
}

void Game::GenerateRaptor()
{
	if (_raptorGenerator.PossibleGenerate())
	{
		std::unique_ptr<Raptor>ptr = std::make_unique<Raptor>(_raptorGenerator.GenerateRaptor(_textureContainer->GetTexture(TextureContainer::raptor)));
		_vectorRaptor.emplace_back(std::move(ptr));
	}
}

void Game::LoadTexture()
{
	_textureContainer->LoadFromFile("Textures/Eagle.png", TextureContainer::eagle);
	_textureContainer->LoadFromFile("Textures/Desert.png", TextureContainer::landScape);
	_textureContainer->LoadFromFile("Textures/Raptor.png", TextureContainer::raptor);
	_textureContainer->LoadFromFile("Textures/Missile.png", TextureContainer::missile);
	_textureContainer->LoadFromFile("Textures/Explosion.png", TextureContainer::explosion);
	_textureContainer->LoadFromFile("Textures/FinishLine.png", TextureContainer::finishLine);
}

void Game::SetUp()
{
	std::unique_ptr<World>tmpPtr = std::make_unique<World>(_textureContainer->GetTexture(TextureContainer::TextureType::landScape));
	std::shared_ptr<Eagle>tmpPtr2 = std::make_shared<Eagle>(_textureContainer->GetTexture(TextureContainer::eagle));

	const std::shared_ptr<Menu>tmpPtr4 = std::make_shared<Menu>();
	const std::shared_ptr<Counter>tmpPtr5 = std::make_shared<Counter>();
	std::unique_ptr<FinishLine>tmpPtr6 = std::make_unique<FinishLine>(_textureContainer->GetTexture(TextureContainer::finishLine));
	tmpPtr6->setRotation(90);
	tmpPtr6->setPosition(200, 0);
	tmpPtr2->setOrigin(24, 32);
	tmpPtr2->setPosition(100, 100);
	tmpPtr2->setRotation(90);
	const sf::Vector2f vector(830, 30);
	tmpPtr5->setPosition(vector);
	_baseObject.push_back(std::move(tmpPtr));
	_baseObject.push_back(std::move(tmpPtr6));
	_ptrEagle = tmpPtr2;
	_eventHandler.LoadMissilesContainer(_ptrMissiles);
	_eventHandler.LoadMissileTexture(_textureContainer);
	_eventHandler.AddEagle(_ptrEagle);
	_eventHandler.SetGamePaused(true);
	_ptrMenu = tmpPtr4;
	_ptrMenu->SetVisibleEntry(true);
	_eventHandler.AddMenu(_ptrMenu);
	_eventHandler.AddWindow(_ptrWindow);
	_ptrCounter = tmpPtr5;
	_eventHandler.AddCounter(_ptrCounter);
}

void Game::DestroyMissileRaptor()
{
	std::vector<std::vector<std::unique_ptr<Missile>>::iterator>toDelate;
	std::vector<std::vector<std::unique_ptr<Raptor>>::iterator>toDelate1;
	for (auto& i : _vectorRaptor)
	{
		for (auto&it : *_ptrMissiles)
		{
			if (_collision.MissileRaptor(*i, *it))
			{
				++*_ptrCounter;
				const auto itMissile = std::find(_ptrMissiles->begin(), _ptrMissiles->end(), it);
				toDelate.push_back(itMissile);
				const auto itRaptor = std::find(_vectorRaptor.begin(), _vectorRaptor.end(), i);
				toDelate1.push_back(itRaptor);
				std::unique_ptr<Animation>tmpPtr = std::make_unique<Animation>(_textureContainer->GetTexture(TextureContainer::explosion), sf::Vector2u(13, 1));
				tmpPtr->setPosition(i->getPosition().x - 98, i->getPosition().y - 95);
				_vectorAnimation.push_back(std::move(tmpPtr));
			}
		}
	}
	for (const auto i : toDelate)
		_ptrMissiles->erase(i);
	for (const auto i : toDelate1)
		_vectorRaptor.erase(i);
}

void Game::RenderMenu()
{
	_ptrWindow->draw(*_ptrMenu);
	_ptrWindow->display();
}
