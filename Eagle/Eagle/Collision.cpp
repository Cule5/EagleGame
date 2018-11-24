#include "Collision.h"
#include <iostream>


Collision::Collision(const double& upperBound, const double& lowerBound, const double&rightBound, const double&finishLine) :_lowerBound(lowerBound), _upperBound(upperBound), _rightBound(rightBound), _finishLine(finishLine)
{
}

Collision::~Collision()
{
}

bool Collision::Upper(const Entity& object) const
{
	const double xOrigin = object.getOrigin().x;
	const double maxDistance = _upperBound + xOrigin;
	if (object.getPosition().y <= maxDistance)
		return true;
	else
		return false;
}

bool Collision::Lower(const Entity& object) const
{
	const double xOrigin = object.getOrigin().x;
	const double width = object.GetLocalBounds().width;
	const double possibleDistance = width - xOrigin;
	if (object.getPosition().y + possibleDistance >= _lowerBound)
		return true;
	else
		return false;
}

bool Collision::FinishLine(const Entity&object) const
{
	const double yOrigin = object.getOrigin().y;
	if (object.getPosition().x <= _finishLine + yOrigin)
		return true;
	return false;
}

bool Collision::Right(const Entity& object) const
{
	const double yOrigin = object.getOrigin().y;
	if (object.getPosition().x >= _rightBound + yOrigin)
		return true;
	return false;
}

bool Collision::MissileRaptor(const Raptor& raptor, const Missile& missile) const
{
	const int raptorRadius = raptor.getOrigin().x;
	const double missileRadius = missile.getOrigin().y;
	const double distance = sqrt(pow(raptor.getPosition().x - missile.getPosition().x, 2) + pow(raptor.getPosition().y - missile.getPosition().y, 2));
	if (distance < missileRadius + raptorRadius)
		return true;
	else
		return false;


}

double Collision::GetUpperBound() const
{
	return _upperBound;
}

double Collision::GetLowerBound() const
{
	return _lowerBound;
}

