#include "EventHandler.h"
#include "Error.h"


EventHandler::EventHandler() :_ptrMissiles(nullptr), _ptrEagle(nullptr), _ptrTexture(nullptr), _isPaused(false), _ptrMenu(nullptr), _ptrCounter(nullptr)
{
}


EventHandler::~EventHandler()
{
}

void EventHandler::AddEvent(const sf::Keyboard::Key& code)
{
	const auto i = std::find(_vectorCode.begin(), _vectorCode.end(), code);
	if (i == _vectorCode.end())
		_vectorCode.push_back(code);
}

void EventHandler::RelaseEvent(const sf::Keyboard::Key& code)
{
	const auto i = std::find(_vectorCode.begin(), _vectorCode.end(), code);
	_vectorCode.erase(i);
}

void EventHandler::SetGamePaused(const bool& paused)
{
	_isPaused = paused;
}

void EventHandler::AddEagle(const std::shared_ptr<Eagle>&ptrEagle)
{
	_ptrEagle = ptrEagle;
}

void EventHandler::MakeEvent()
{
	sf::Vector2f movement;
	if (_ptrEagle == nullptr)
		throw Error("Nie wczytano obiektu typu Eagle");
	for (auto i : _vectorCode)
	{
		if (i == sf::Keyboard::Up)
		{
			movement.y = -500;
			_ptrEagle->SetVelocity(movement);
		}
		else if (i == sf::Keyboard::Down)
		{
			movement.y = 500;
			_ptrEagle->SetVelocity(movement);
		}
		else if (i == sf::Keyboard::Space)
		{
			if (_ptrMissiles == nullptr)
				throw Error("Nie wczytano kontenera na pociski do obiektu typu EventHandler");
			if (_ptrEagle->PossibleShot())
			{
				if (_ptrTexture == nullptr)
					throw Error("Nie wczytano textury pocisku do obiektu EventHandler");
				MakeMissile();
			}
		}
		else if (i == sf::Keyboard::Escape)
		{
			_isPaused = true;
			_ptrMenu->SetVisiblePause(true);
		}

	}
	_ptrEagle->SetVelocity(movement);
}

void EventHandler::MakeMenuEvent()
{
	if (_ptrWindow == nullptr)
		throw Error("Nie wczytano obietu typu Window do obiektu EventHandler");
	if (_ptrMenu == nullptr)
		throw Error("Nie wczytano obiektu typu Menu do obiektu EventHandler");
	for (auto i : _vectorCode)
	{
		if (i == sf::Keyboard::Up)
			_ptrMenu->MoveUp();
		else if (i == sf::Keyboard::Down)
			_ptrMenu->MoveDown();
		else if (i == sf::Keyboard::Space)
		{
			const int position = _ptrMenu->GetActuallButton();
			if (_ptrMenu->GetVisibleEntry())
			{
				if (position == 0)
				{
					_isPaused = false;
					_ptrMenu->ResetMenu();
					Sleep(1000);
				}
				else if (position == 2)
				{
					_ptrWindow->close();
				}
				else if (position == 1)
				{
					_ptrCounter->LoadFromFile();
					_isPaused = false;
					_ptrMenu->ResetMenu();
					Sleep(1000);
				}
				else if (position == 3)
				{
					_ptrMenu->ResetMenu();
					_ptrMenu->SetVisibleResults(true);
					sf::Sprite sprite;
					sprite.setTexture(_ptrTexture->GetTexture(_ptrTexture->landScape));
					_ptrWindow->clear();
				}
			}
			else if (_ptrMenu->GetVisiblePause())
			{
				if (position == 0)
				{
					_isPaused = false;
					_ptrMenu->ResetMenu();
				}
				else if (position == 2)
					_ptrWindow->close();
				else if (position == 1)
					_ptrCounter->LoadToFile();
			}
			else if (_ptrMenu->GetVisibleResultsMenu())
			{
				_ptrMenu->ResetMenu();
				_ptrMenu->SetVisibleEntry(true);
			}
			else if (_ptrMenu->GetVisibleExit())
				_ptrWindow->close();
		}
	}
}



void EventHandler::LoadMissilesContainer(const std::shared_ptr<std::vector<std::unique_ptr<Missile>>>& ptrMissiles)
{
	_ptrMissiles = ptrMissiles;

}

void EventHandler::LoadMissileTexture(const std::shared_ptr<TextureContainer>& ptrTexture)
{
	_ptrTexture = ptrTexture;
}

void EventHandler::AddMenu(const std::shared_ptr<Menu>& ptrMenu)
{
	_ptrMenu = ptrMenu;

}

void EventHandler::AddWindow(const std::shared_ptr<sf::RenderWindow>& ptrWindow)
{
	_ptrWindow = ptrWindow;

}

void EventHandler::AddCounter(const std::shared_ptr<Counter>& ptrCounter)
{
	_ptrCounter = ptrCounter;
}

bool EventHandler::IsGamePaused() const
{
	return _isPaused;
}

void EventHandler::MakeMissile()
{
	std::unique_ptr<Missile>ptrMissile = std::make_unique<Missile>((*_ptrTexture).GetTexture(_ptrTexture->missile));
	const sf::Vector2f vector(700, 0);
	ptrMissile->SetVelocity(vector);
	ptrMissile->setRotation(90);
	ptrMissile->setOrigin(7.5, 16);
	ptrMissile->setPosition(_ptrEagle->getPosition().x + _ptrEagle->getOrigin().y + 16, _ptrEagle->getPosition().y);
	_ptrMissiles->emplace_back(std::move(ptrMissile));
}
