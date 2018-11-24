#include "EntryMenu.h"

EntryMenu::EntryMenu() :_isVisible(false), TextObject()
{
}


EntryMenu::~EntryMenu()
{
}

bool EntryMenu::IsVisible() const
{
	return _isVisible;
}

void EntryMenu::SetVisibility(const bool visibility)
{
	_isVisible = visibility;
}

void EntryMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{



	for (auto i : _buttonMap)
	{
		target.draw(i.second, states);
	}


}

void EntryMenu::CreatePlay()
{
	sf::Text tmpText;
	tmpText.setFont(_font);
	tmpText.setFillColor(sf::Color::Red);
	tmpText.setString("PLAY");
	const sf::Vector2f vector(500, 300);
	tmpText.setPosition(vector);
	_buttonMap.insert({ play,tmpText });
}

void EntryMenu::CreateLoad()
{
	sf::Text tmpText;
	tmpText.setFont(_font);
	tmpText.setString("LOAD");
	tmpText.setFillColor(sf::Color::Red);
	const sf::Vector2f vector(500, 500);
	tmpText.setPosition(vector);
	_buttonMap.insert({ load,tmpText });

}

void EntryMenu::CreateExit()
{
	sf::Text tmpText;
	tmpText.setFont(_font);
	tmpText.setString("EXIT");
	tmpText.setFillColor(sf::Color::Red);
	const sf::Vector2f vector(500, 700);
	tmpText.setPosition(vector);
	_buttonMap.insert({ exit,tmpText });
}
