#pragma once
#include<SFML/Graphics.hpp>
class TextObject :public sf::Transformable, public sf::Drawable
{
public:
	TextObject();
	~TextObject();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
protected:
	sf::Font _font;
	virtual void SetUp();
};

