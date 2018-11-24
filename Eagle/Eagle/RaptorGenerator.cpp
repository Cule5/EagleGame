#include "RaptorGenerator.h"



RaptorGenerator::RaptorGenerator() :_xPosition(1034), _yPosition(0), _xOrigin(34), _yOrigin(42), _xVelocity(0), _rotation(-90), _yVelocity(0)
{
	srand(time(nullptr));
}


RaptorGenerator::~RaptorGenerator()
{
}

Raptor RaptorGenerator::GenerateRaptor(const sf::Texture &texture)
{
	Raptor newRaptor(texture);
	GeneratePosition();
	GenerateVelocity();
	newRaptor.setOrigin(_yOrigin, _xOrigin);
	newRaptor.setRotation(_rotation);
	newRaptor.setPosition(_xPosition, _yPosition);
	const sf::Vector2f vector(_xVelocity, _yVelocity);
	newRaptor.SetVelocity(vector);
	return newRaptor;
}

bool RaptorGenerator::PossibleGenerate()
{
	_time = _clock.getElapsedTime();
	const double minimalTime = 1.25;
	if (_time.asSeconds() >= minimalTime)
	{
		_time = _clock.restart();
		return true;
	}
	return false;
}

void RaptorGenerator::GeneratePosition()
{
	_yPosition = rand() % (500 - _xOrigin);
}

void RaptorGenerator::GenerateVelocity()
{
	_xVelocity = -(rand() % 400 + 400);
	const int tmp = rand() % 3;
	if (tmp == 0)
		_yVelocity = rand() % 400 + 350;
	else if (tmp == 1)
		_yVelocity = -(rand() % 400 + 350);
	else if (tmp == 2)
		_yVelocity = 0;
}
