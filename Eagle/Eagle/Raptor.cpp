#include "Raptor.h"



Raptor::Raptor(const sf::Texture& texture) :Entity(texture)
{

}

Raptor::~Raptor()
{
}

void Raptor::SetVelocity(const sf::Vector2f& velocity)
{
	_velocity = velocity;
}

sf::Vector2f Raptor::GetVelocity() const
{
	return _velocity;
}

void Raptor::Update(const sf::Time deltaTime)
{
	move(deltaTime.asSeconds()*_velocity);
}

