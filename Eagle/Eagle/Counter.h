#pragma once
#include<SFML/Graphics.hpp>
#include<sstream>
#include "TextObject.h"
#include <fstream>
class Counter :public TextObject
{
public:
	Counter();
	~Counter();
	//wyswietlanie licznika na ekranie
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	//inkrementacja licznika
	void operator++();
	//odczut z pliku stanu licznika
	void LoadFromFile();
	//zapis do pliku stanu licznika
	void LoadToFile();
	//zwrocenie ilosci punktow
	int GetPoints()const;
private:

	void SetText();
	void SetUp()override;
	int _destroyCounter;
	sf::Text _text;

};

