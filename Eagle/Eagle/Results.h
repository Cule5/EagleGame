#pragma once
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
#include"TextObject.h"
class Results :public TextObject
{
public:
	Results();
	~Results();
	//rysowanie tabeli wynikow na ekranie
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	//zaladowanie tabeli wynikow z pliku
	void LoadFromFile();
	//zaladowanie tabeli wynikow do pliku
	void LoadToFile();
	//dodanie nowego rekordu do tabeli
	void AddProfile(const std::string&nick, const int result);
private:
	struct Profile
	{
		int _point;
		std::string _nick;
		sf::Text _text;
		bool operator<(const Profile& obj)
		{
			return _point > obj._point;
		}
	};
	sf::Text SetText(std::string&nick, const int result)const;
	std::vector<Profile>_vectorResults;
};

