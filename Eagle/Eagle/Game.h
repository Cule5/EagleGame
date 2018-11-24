#pragma once
#include<SFML/Graphics.hpp>
#include"TextureContainer.h"
#include <memory>
#include"World.h"
#include"Eagle.h"
#include<vector>
#include"Raptor.h"
#include"Collision.h"
#include"Missile.h"
#include"RaptorGenerator.h"
#include"AI.h"
#include"EventHandler.h"
#include "Animation.h"
#include "Counter.h"


class Game
{
public:
	Game();
	~Game();
	//uruchomienie gry
	void Run();
private:
	std::shared_ptr<TextureContainer>_textureContainer;
	Collision _collision;
	RaptorGenerator _raptorGenerator;
	AI _ai;
	EventHandler _eventHandler;
	std::shared_ptr<Counter>_ptrCounter;
	std::shared_ptr<Menu>_ptrMenu;
	std::shared_ptr<sf::RenderWindow>_ptrWindow;
	std::shared_ptr<Eagle>_ptrEagle;
	std::vector<std::unique_ptr<Entity>>_baseObject;
	std::vector<std::unique_ptr<Raptor>>_vectorRaptor;
	std::vector<std::unique_ptr<Animation>>_vectorAnimation;
	std::shared_ptr<std::vector<std::unique_ptr<Missile>>>_ptrMissiles;
	void KeyPressed(const sf::Event::KeyEvent& event);
	void KeyRelesed(const sf::Event::KeyEvent& event);
	void Update(const sf::Time deltaTime);
	void Render();
	void HandleInput();
	void GenerateRaptor();
	void LoadTexture();
	void SetUp();
	void DestroyMissileRaptor();
	void RenderMenu();
};
