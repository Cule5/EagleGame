#include "TextureContainer.h"



TextureContainer::TextureContainer()
{
}


TextureContainer::~TextureContainer()
{
}

void TextureContainer::LoadFromFile(const std::string& fileName, TextureType type)
{
	sf::Texture newTexture;
	if (newTexture.loadFromFile(fileName))
		_mapTexture.insert({ type,std::make_unique<sf::Texture>(newTexture) });
}

sf::Texture& TextureContainer::GetTexture(const TextureType& type)
{
	return *_mapTexture.at(type);
}
