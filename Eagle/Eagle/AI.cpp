#include "AI.h"



AI::AI() :_collision(0, 500, 1000, 200)
{
}


AI::~AI()
{
}

void AI::EagleChanger(Eagle& object)
{
	if (_collision.Upper(object))
		object.setPosition(object.getPosition().x, 24);
	else if (_collision.Lower(object))
		object.setPosition(100, 476);
}

void AI::RaptorChanger(Raptor& object)const
{
	if (_collision.Upper(object))
	{
		const double xVelocity = object.GetVelocity().x;
		const double yVelocity = object.GetVelocity().y;
		const double xOrigin = object.getOrigin().x;
		const double xPos = object.getPosition().x - xVelocity;
		const double yPos = object.getPosition().y - yVelocity;
		const double xCalculate = ((_collision.GetUpperBound() - yPos)*(object.getPosition().x - xPos) + xPos * (object.getPosition().y - yPos)) / (object.getPosition().y - yPos);
		object.setPosition(xCalculate, _collision.GetUpperBound() + xOrigin);
		const sf::Vector2f vector(xVelocity, -yVelocity);
		object.SetVelocity(vector);
	}
	else if (_collision.Lower(object))
	{
		const double xVelocity = object.GetVelocity().x;
		const double yVelocity = object.GetVelocity().y;
		const double xOrigin = object.getOrigin().x;
		const double xPos = object.getPosition().x - xVelocity;
		const double yPos = object.getPosition().y - yVelocity;
		const double xCalculate = ((_collision.GetLowerBound() - yPos)*(object.getPosition().x - xPos) + xPos * (object.getPosition().y - yPos)) / (object.getPosition().y - yPos);
		object.setPosition(xCalculate, _collision.GetLowerBound() - xOrigin);
		const sf::Vector2f vector(xVelocity, -yVelocity);
		object.SetVelocity(vector);
	}
}
