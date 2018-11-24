#pragma once
#include"Entity.h"
class Missile : public Entity
{
public:
	Missile(const sf::Texture& texture);
	~Missile();
	//ustawienie predkosci pocisku
	void SetVelocity(const sf::Vector2f& velocity);
	//zwrocenie wektora predkosci pocisku
	sf::Vector2f GetVelocity()const;
	//update pozycji pocisku
	void Update(const sf::Time deltaTime);
private:
	sf::Vector2f _velocity;
};