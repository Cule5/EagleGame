#pragma once
#include"Entity.h"
#include"Raptor.h"
#include"Missile.h"
//klasa zajmujaca sie wykrywanie kolizji
class Collision
{
public:
	Collision(const double& upperBound, const double& lowerBound, const double&rightBound, const double&finishLine);
	~Collision();
	//sprawdzanie czy nastapila kolizja z gorna banda
	bool Upper(const Entity&object)const;
	//sprawdznie czy nastapila kolizja z dolna banda
	bool Lower(const Entity&object)const;
	bool FinishLine(const Entity&object)const;
	//sprawdzenie czy nastapila kolizja z prawa banda
	bool Right(const Entity&object)const;
	//sprawdznie cz nastapila kolizja pomiedzy pociskiem a Raptorem
	bool MissileRaptor(const Raptor& raptor, const Missile&missile)const;
	//zwraca polozenie gornej bandy
	double GetUpperBound()const;
	//zwraca polozenie dolnej bandy
	double GetLowerBound()const;
private:
	const double _upperBound;
	const double _lowerBound;
	const double _rightBound;
	const double _finishLine;
};
