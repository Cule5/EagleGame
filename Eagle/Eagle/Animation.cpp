#include "Animation.h"



Animation::Animation(sf::Texture&texture, const sf::Vector2u&imageCount) :Entity(texture), _amountPicture(13), _actualNumber(0), _switchTime(0.05), _totalTime(0.0)
{
	_imageCount = imageCount;
	_currnetImage.x = 0;
	_intRect.width = _texture.getSize().x / double(_imageCount.x);
	_intRect.height = _texture.getSize().y / double(_imageCount.y);
}


Animation::~Animation()
{
}

void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
}

void Animation::Update(sf::Time deltaTime)
{
	_totalTime += deltaTime.asSeconds();
	if (_totalTime >= _switchTime)
	{
		_totalTime -= _switchTime;
		++_actualNumber;
		++_currnetImage.x;
		if (_currnetImage.x >= _imageCount.x)
			_currnetImage.x = 0;
	}
	_intRect.left = _currnetImage.x*_intRect.width;
	_intRect.top = _currnetImage.y*_intRect.height;
	_sprite.setTextureRect(_intRect);

}

bool Animation::IsFinish()
{
	if (_actualNumber == _amountPicture)
		return true;
	else
		return false;
}

