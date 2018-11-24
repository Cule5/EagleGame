#pragma once
#include<SFML/Graphics.hpp>
class Entity :public sf::Drawable, public sf::Transformable
{
public:
	Entity(const sf::Texture& texture);
	~Entity();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void Update(const sf::Time deltaTime)const;
	sf::Rect<float> GetLocalBounds()const;
protected:
	sf::Sprite _sprite;
	const sf::Texture& _texture;
};