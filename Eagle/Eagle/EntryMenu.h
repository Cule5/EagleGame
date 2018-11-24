#pragma once
#include "TextObject.h"

class EntryMenu :public TextObject
{
public:
	EntryMenu();
	~EntryMenu();
	bool IsVisible()const;
	void SetVisibility(const bool visibility);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	void CreatePlay();
	void CreateLoad();
	void CreateExit();
	enum Buttons { play, load, exit };
	bool _isVisible;
	std::map<Buttons, sf::Text>_buttonMap;
};

