#pragma once
#include"Entity.h"
class Eagle :public Entity
{
public:
	Eagle(const sf::Texture& texture);
	~Eagle();
	//sprawdzanie mozliwosci oddania strzalu
	bool PossibleShot();
	//ustawienie predkosci 
	void SetVelocity(const sf::Vector2f& velocity);
	//zwrocnie aktualnego wektora predkosci
	sf::Vector2f GetVelocity()const;
	//update pozycji
	void Update(const sf::Time deltaTime);
private:
	sf::Time _time;
	sf::Clock _clock;
	sf::Vector2f _velocity;
};