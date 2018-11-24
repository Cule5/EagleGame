#pragma once
#include"Raptor.h"
#include<ctime>
class RaptorGenerator
{
public:
	RaptorGenerator();
	~RaptorGenerator();
	//generowanie obiektu typu raptor
	Raptor GenerateRaptor(const sf::Texture& texture);
	//sprawdzanie czy jest mozliwe generowanie
	bool PossibleGenerate();
private:
	void GeneratePosition();
	void GenerateVelocity();
	sf::Time _time;
	sf::Clock _clock;
	int _yPosition;
	int _yVelocity;
	int _xVelocity;
	const int _xOrigin;
	const int _yOrigin;
	const int _rotation;
	const int _xPosition;
};