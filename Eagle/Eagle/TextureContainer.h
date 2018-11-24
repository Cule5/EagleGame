#pragma once
#include<map>
#include<memory>
#include<SFML/Graphics.hpp>
#include<string>
class TextureContainer
{
public:
	TextureContainer();
	~TextureContainer();
	//enum z typami tekstur w programie
	enum TextureType { eagle, landScape, raptor, missile, gameOver, explosion, finishLine };
	//ladowanie tekstury z pliku
	void LoadFromFile(const std::string&fileName, TextureType type);
	//zwrocenie tektury 
	sf::Texture& GetTexture(const TextureType& type);
private:
	std::map<TextureType, std::unique_ptr<sf::Texture>> _mapTexture;
};