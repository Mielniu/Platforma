#pragma once

#include <SFML\Graphics.hpp>

class General
{
public:
	General();
	~General();

	void run();

private:
	sf::RenderWindow windows;
	size_t windowsWidth = 800;
	size_t windowsHeight = 566;
	sf::String windowsName = "Okno";

	sf::Event event;
};