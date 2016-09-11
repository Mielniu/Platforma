#pragma once

#include <SFML\Graphics.hpp>
#include "LoadMap.h"


class General
{
public:
	General();
	~General();

	void run();
	void draw();
	void startmap();

	LoadMap map;

private:
	sf::RenderWindow windows;
	size_t windowsWidth = 800;
	size_t windowsHeight = 566;
	sf::String windowsName = "Okno";

	sf::Event event;
};