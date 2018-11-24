#pragma once
#include<SFML/Graphics.hpp>
#include "Entity.h"

//klasa zajmujaca sie generowaniem animacji
class Animation :public Entity
{
public:
	Animation(sf::Texture&texture, const sf::Vector2u&imageCount);
	~Animation();
	//przesylanie animacji do okna
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	//update animacji
	void Update(sf::Time deltaTime);
	//sprawdzajanie czy wyswietlanie animacji dobieglo konca
	bool IsFinish();
private:
	double _switchTime;
	double _totalTime;
	sf::IntRect _intRect;
	sf::Vector2u _imageCount;
	sf::Vector2u _currnetImage;
	const int _amountPicture;
	int _actualNumber;
};