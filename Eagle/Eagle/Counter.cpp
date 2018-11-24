#include "Counter.h"
#include "Error.h"


Counter::Counter() :_destroyCounter(0)
{
	Counter::SetUp();
	SetText();
}

Counter::~Counter()
{
}

void Counter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(_text, states);
}

void Counter::operator++()
{
	++_destroyCounter;
	SetText();
}

void Counter::LoadFromFile()
{
	std::ifstream file;
	file.open("LOAD.txt");
	if (!file.is_open())
		throw Error("Nie wczytano ilosci punktow z pliku");
	file >> _destroyCounter;
	SetText();
}

void Counter::LoadToFile()
{
	std::ofstream file;
	file.open("LOAD.txt");
	if (!file.is_open())
		throw Error("Nie zapisano ilosci puntow do pliku");
	file << _destroyCounter;
}

int Counter::GetPoints() const
{
	return _destroyCounter;
}

void Counter::SetText()
{
	std::ostringstream ss;
	ss << _destroyCounter;
	const std::string string = "PUNKTY: ";
	const std::string str = ss.str();
	_text.setString(string + str);
}

void Counter::SetUp()
{
	TextObject::SetUp();
	_text.setFont(_font);
	_text.setFillColor(sf::Color::Black);
}
