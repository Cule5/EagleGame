#include "Missile.h"
Missile::Missile(const sf::Texture&texture) :Entity(texture)
{

}

Missile::~Missile()
{
}

void Missile::SetVelocity(const sf::Vector2f& velocity)
{
	_velocity = velocity;
}

sf::Vector2f Missile::GetVelocity() const
{
	return _velocity;
}

void Missile::Update(const sf::Time deltaTime)
{
	move(deltaTime.asSeconds()*_velocity);
}
