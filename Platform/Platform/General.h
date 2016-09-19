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
	void postac();
	void fizyka();
	void ruch(int kierunek);
	bool kolizje(int jaka);

	LoadMap map;

private:
	sf::RenderWindow windows;
	size_t windowsWidth = 800;
	size_t windowsHeight = 560;
	sf::String windowsName = "Okno";

	sf::Event event;

	sf::Texture texturepostac;
	sf::Sprite spritepostac;
	sf::Vector2f positionpostac;
	int wysokoscpostaci = 120;
	int szerokoscpostaci = 40;
	int masapostaci = 8;

	int skok = 0;
	bool endskok = false;
	int kolizja = 11 * 40;
};