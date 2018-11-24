#pragma once
#include"Entity.h"
class Raptor :public Entity
{
public:
	Raptor(const sf::Texture& texture);
	~Raptor();
	//ustawienie predosci raptora
	void SetVelocity(const sf::Vector2f& velocity);
	//zwrocenie wektora predkosci raptora
	sf::Vector2f GetVelocity()const;
	//update pozycji raptora
	void Update(const sf::Time deltaTime);
private:
	sf::Vector2f _velocity;
};