#include "Menu.h"



Menu::Menu() :TextObject(), _isVisibleEntryMenu(false), _isVisiblePauseMenu(false), _isVissibleResultsMenu(false), _isVisibleExitMenu(false), _actualButton(0)
{
	TextObject::SetUp();
	CreateContinue();
	CreateSave();
	CreatePlay();
	CreateLoad();
	CreateExit();
	CreateResults();
	_results.LoadFromFile();
	srand(time(nullptr));
}


Menu::~Menu()
{
	_results.LoadToFile();
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Texture texture;
	texture.loadFromFile("Textures/Desert.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	target.draw(sprite);
	if (_isVisibleEntryMenu)
	{
		for (const auto& i : _entryMenuButtons)
			target.draw(i);
	}
	else if (_isVisiblePauseMenu)
	{
		for (const auto& i : _pauseMenuButtons)
			target.draw(i);
	}
	else if (_isVisibleExitMenu)
	{
		target.draw(_info);
		for (const auto&i : _exitMenuButtons)
			target.draw(i);

	}
	else if (_isVissibleResultsMenu)
	{
		target.draw(_results);
		for (const auto&i : _resultsMenuButtons)
			target.draw(i);
	}
}

void Menu::SetVisibleEntry(const bool visible)
{
	_isVisibleEntryMenu = visible;
}

void Menu::SetVisiblePause(const bool visible)
{
	_isVisiblePauseMenu = visible;
}

void Menu::SetVisibleExit(const bool visible)
{
	_isVisibleExitMenu = visible;
}

void Menu::SetVisibleResults(const bool visible)
{
	_isVissibleResultsMenu = visible;
}

void Menu::MoveDown()
{
	if (_isVisibleEntryMenu)
	{
		++_actualButton;
		if (_actualButton == _entryMenuButtons.size())
		{
			_entryMenuButtons[_actualButton - 1].setFillColor(sf::Color::White);
			_actualButton = 0;
			_entryMenuButtons[_actualButton].setFillColor(sf::Color::Red);
		}
		else
		{
			_entryMenuButtons[_actualButton - 1].setFillColor(sf::Color::White);
			_entryMenuButtons[_actualButton].setFillColor(sf::Color::Red);
		}
	}
	else if (_isVisiblePauseMenu)
	{
		++_actualButton;
		if (_actualButton == _pauseMenuButtons.size())
		{
			_pauseMenuButtons[_actualButton - 1].setFillColor(sf::Color::White);
			_actualButton = 0;
			_pauseMenuButtons[_actualButton].setFillColor(sf::Color::Red);
		}
		else
		{
			_pauseMenuButtons[_actualButton - 1].setFillColor(sf::Color::White);
			_pauseMenuButtons[_actualButton].setFillColor(sf::Color::Red);
		}
	}
}

void Menu::MoveUp()
{
	if (_isVisibleEntryMenu)
	{
		--_actualButton;
		if (_actualButton == -1)
		{
			_entryMenuButtons[_actualButton + 1].setFillColor(sf::Color::White);
			_actualButton = _entryMenuButtons.size() - 1;
			_entryMenuButtons[_actualButton].setFillColor(sf::Color::Red);
			_actualButton = 3;
		}
		else
		{
			_entryMenuButtons[_actualButton].setFillColor(sf::Color::Red);
			_entryMenuButtons[_actualButton + 1].setFillColor(sf::Color::White);
		}
	}
	else if (_isVisiblePauseMenu)
	{
		--_actualButton;
		if (_actualButton == -1)
		{
			_pauseMenuButtons[_actualButton + 1].setFillColor(sf::Color::White);
			_actualButton = _pauseMenuButtons.size() - 1;
			_pauseMenuButtons[_actualButton].setFillColor(sf::Color::Red);
			_actualButton = 3;
		}
		else
		{
			_pauseMenuButtons[_actualButton].setFillColor(sf::Color::Red);
			_pauseMenuButtons[_actualButton + 1].setFillColor(sf::Color::White);
		}
	}
}

void Menu::ResetMenu()
{
	_actualButton = 0;
	_isVisibleEntryMenu = false;
	_isVisibleExitMenu = false;
	_isVisiblePauseMenu = false;
	_isVissibleResultsMenu = false;
}

void Menu::LoadResult(const int result)
{
	const std::string nick = GenerateNick();
	_results.AddProfile(nick, result);
	CreateInfo(nick);
}

int Menu::GetActuallButton() const
{
	return _actualButton;
}

bool Menu::GetVisibleEntry() const
{
	return _isVisibleEntryMenu;
}

bool Menu::GetVisiblePause() const
{
	return _isVisiblePauseMenu;
}

bool Menu::GetVisibleResultsMenu() const
{
	return _isVissibleResultsMenu;
}

bool Menu::GetVisibleExit() const
{
	return _isVisibleExitMenu;
}

std::string Menu::GenerateNick()const
{
	const std::string partNick = "EAGLE";
	const int number = rand() % 1000;
	std::ostringstream ss;
	ss << number;
	const std::string str = ss.str();
	std::string nick = partNick + str;
	return nick;
}

void Menu::CreatePlay()
{
	sf::Text tmpText;
	tmpText.setFont(_font);
	tmpText.setFillColor(sf::Color::Red);
	tmpText.setString("PLAY");
	const sf::Vector2f vector(470, 100);
	tmpText.setPosition(vector);
	_entryMenuButtons.push_back(tmpText);
}

void Menu::CreateExit()
{
	sf::Text tmpText;
	tmpText.setFont(_font);
	tmpText.setFillColor(sf::Color::White);
	tmpText.setString("EXIT");
	const sf::Vector2f vector(470, 300);
	tmpText.setPosition(vector);
	_entryMenuButtons.push_back(tmpText);
	const sf::Vector2f vector1(467, 300);
	tmpText.setPosition(vector1);
	_pauseMenuButtons.push_back(tmpText);
	tmpText.setFillColor(sf::Color::Red);
	_exitMenuButtons.push_back(tmpText);
	_resultsMenuButtons.push_back(tmpText);
}

void Menu::CreateLoad()
{
	sf::Text tmpText;
	tmpText.setFont(_font);
	tmpText.setFillColor(sf::Color::White);
	tmpText.setString("LOAD");
	const sf::Vector2f vector(460, 200);
	tmpText.setPosition(vector);
	_entryMenuButtons.push_back(tmpText);
}

void Menu::CreateSave()
{
	sf::Text tmpText;
	tmpText.setFont(_font);
	tmpText.setFillColor(sf::Color::White);
	tmpText.setString("SAVE");
	const sf::Vector2f vector(460, 200);
	tmpText.setPosition(vector);
	_pauseMenuButtons.push_back(tmpText);
}

void Menu::CreateContinue()
{
	sf::Text tmpText;
	tmpText.setFont(_font);
	tmpText.setFillColor(sf::Color::Red);
	tmpText.setString("CONTINUE");
	const sf::Vector2f vector(430, 100);
	tmpText.setPosition(vector);
	_pauseMenuButtons.push_back(tmpText);
}

void Menu::CreateResults()
{
	sf::Text tmpText;
	tmpText.setFont(_font);
	tmpText.setFillColor(sf::Color::White);
	tmpText.setString("RESULTS");
	tmpText.setPosition(440, 400);
	_entryMenuButtons.push_back(tmpText);
}

void Menu::CreateInfo(const std::string&nick)
{
	_info.setFont(_font);
	_info.setFillColor(sf::Color::White);
	_info.setString("TWOJ NICK TO: " + nick);
	_info.setPosition(0, 0);
}
