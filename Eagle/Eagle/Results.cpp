#include "Results.h"
#include "Error.h"


Results::Results()
{
}


Results::~Results()
{

}

void Results::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	int pos = 0;

	for (auto i : _vectorResults)
	{

		sf::Text text;
		text = i._text;
		text.setPosition(0, pos);
		pos += 100;
		target.draw(text);
	}


}

void Results::LoadFromFile()
{
	std::ifstream file;
	file.open("RESULT.txt");
	if (!file.is_open())
		throw Error("Nie wczytano pliku z rezultatami");
	std::string nick;
	while (file >> nick)
	{
		int result;
		TextObject::SetUp();
		file >> result;
		sf::Text text = SetText(nick, result);
		Profile tmp;
		tmp._point = result;
		tmp._nick = nick;
		tmp._text = text;
		_vectorResults.push_back(tmp);
	}
}

void Results::LoadToFile()
{
	std::ofstream file;
	file.open("RESULT.txt");
	if (!file.is_open())
		throw Error("Nie udalo sie otworzyc pliku do zapisu rezultatow");
	for (const auto&i : _vectorResults)
		file << i._nick << " " << i._point << std::endl;
}

void Results::AddProfile(const std::string& nick, const int result)
{
	Profile tmp;
	tmp._nick = nick;
	tmp._point = result;
	_vectorResults.push_back(tmp);
	std::sort(_vectorResults.begin(), _vectorResults.end());
}

sf::Text Results::SetText(std::string&nick, const int result)const
{
	std::ostringstream ss;
	ss << result;
	const std::string str = ss.str();
	sf::Text tmpText;
	tmpText.setFont(_font);
	tmpText.setFillColor(sf::Color::White);
	tmpText.setString(nick + "    " + str);
	return tmpText;
}
