#pragma once
#include"Entity.h"

class World :public Entity
{
public:
	World(const sf::Texture& texture);
	~World();
};