#include "Entity.h"

Entity::Entity(const sf::Texture& texture) :_texture(texture)
{
	_sprite.setTexture(_texture);
}

Entity::~Entity()
{
}


void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(_sprite, states);
}

void Entity::Update(const sf::Time deltaTime) const
{
}


sf::Rect<float> Entity::GetLocalBounds() const
{
	return _sprite.getLocalBounds();
}
