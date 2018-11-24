#pragma once
#include "TextObject.h"
#include "Results.h"


class Menu :public TextObject
{
public:
	Menu();
	~Menu();
	//wyswietlanie menu
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	//ustawienie widocznosci menu wejsciowego
	void SetVisibleEntry(const bool visible);
	//ustawinie widocznosci menu pausa
	void SetVisiblePause(const bool visible);
	//ustawienie widocznosci menu wyjsciowego
	void SetVisibleExit(const bool visible);
	//ustawienie widocznosci menu z rezultatami
	void SetVisibleResults(const bool visible);
	//przesuniecie w dol wskaznika wyboru opcji w menu
	void MoveDown();
	//przesuniecie do gory wskaznika wyboru opcji w menu
	void MoveUp();
	//restart menu
	void ResetMenu();
	//zaladowanie do menu wyniku gry
	void LoadResult(const int result);
	//zwracanie, ktory aktualnie przycisk menu jest wybrany
	int GetActuallButton()const;
	//zwracanie widocznosci menu wejsciowego
	bool GetVisibleEntry()const;
	//zwracanie widocznosci menu pausa
	bool GetVisiblePause()const;
	//zwracanie widocznosci menu z rezultatami
	bool GetVisibleResultsMenu()const;
	//zwracanie widocznosci menu wyjsciowego
	bool GetVisibleExit()const;
private:
	bool _isVisibleEntryMenu;
	bool _isVisiblePauseMenu;
	bool _isVisibleExitMenu;
	bool _isVissibleResultsMenu;
	std::vector<sf::Text>_entryMenuButtons;
	std::vector<sf::Text>_pauseMenuButtons;
	std::vector<sf::Text>_exitMenuButtons;
	std::vector<sf::Text>_resultsMenuButtons;
	Results _results;
	std::string GenerateNick()const;
	void CreatePlay();
	void CreateExit();
	void CreateLoad();
	void CreateSave();
	void CreateContinue();
	void CreateResults();
	void CreateInfo(const std::string&nick);
	int _actualButton;
	sf::Text _info;
};

