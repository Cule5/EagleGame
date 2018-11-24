#pragma once
#include"Collision.h"
#include "Raptor.h"
#include"Eagle.h"

//Klasa odpowaidajaca za sztuczna inteligencje
class AI
{
public:
	AI();
	~AI();
	//metoda zarzadzajaca zakresem ruchow Eagle'a
	void EagleChanger(Eagle&object);
	//meoda zarz¹dzajaca zakresem ruchow raptora
	void RaptorChanger(Raptor&object)const;
private:
	Collision _collision;
};