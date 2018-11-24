#include "Eagle.h"

Eagle::Eagle(const sf::Texture& texture) :Entity(texture)
{

}

Eagle::~Eagle()
{
}

bool Eagle::PossibleShot()
{
	_time = _clock.getElapsedTime();
	const double minimalTime = 0.35;
	if (_time.asSeconds() >= minimalTime)
	{
		_time = _clock.restart();
		return true;
	}
	return false;
}

void Eagle::SetVelocity(const sf::Vector2f& velocity)
{
	_velocity = velocity;
}

sf::Vector2f Eagle::GetVelocity() const
{
	return _velocity;
}

void Eagle::Update(const sf::Time deltaTime)
{
	move(deltaTime.asSeconds()*_velocity);
}
