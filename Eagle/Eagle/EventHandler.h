#pragma once
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include<algorithm>
#include <memory>
#include"Eagle.h"
#include"Missile.h"
#include "Menu.h"
#include<Windows.h>
#include "Counter.h"
#include "TextureContainer.h"

//klasa zarzadzajaca zdarzeniami
class EventHandler
{
public:
	EventHandler();
	~EventHandler();
	//dodanie nowego zdarzenia
	void AddEvent(const sf::Keyboard::Key&code);
	//usunieniencie zdarzenia
	void RelaseEvent(const sf::Keyboard::Key&code);
	//zaladowanie obiektu typu Eagle
	void SetGamePaused(const bool&paused);
	void AddEagle(const std::shared_ptr<Eagle>&ptrEagle);
	//wykonanie zdarzen znajdujacych sie w obiekcie
	void MakeEvent();
	//wykonanie zdarzen dotyczacych menu
	void MakeMenuEvent();
	//zaladowanie kontenera z pociskami
	void LoadMissilesContainer(const std::shared_ptr< std::vector<std::unique_ptr<Missile>>>&ptrMissiles);
	//zaladowanie textury pocisku
	void LoadMissileTexture(const std::shared_ptr<TextureContainer>&ptrTexture);
	void AddMenu(const std::shared_ptr<Menu>&ptrMenu);
	//sprawdzenie czy gra powinna zostac zatrzymana
	void AddWindow(const std::shared_ptr<sf::RenderWindow>&ptrWindow);
	//dodanie licznika do obiektu
	void AddCounter(const std::shared_ptr<Counter>&ptrCounter);
	//sprawdzenie czy gra jest zapauzowana
	bool IsGamePaused()const;
private:
	void MakeMissile();
	std::vector<sf::Keyboard::Key>_vectorCode;
	std::shared_ptr<Eagle>_ptrEagle;
	std::shared_ptr< std::vector<std::unique_ptr<Missile>>>_ptrMissiles;
	std::shared_ptr<TextureContainer>_ptrTexture;
	std::shared_ptr<Menu>_ptrMenu;
	std::shared_ptr<sf::RenderWindow>_ptrWindow;
	std::shared_ptr<Counter>_ptrCounter;
	bool _isPaused;

};