#include "General.h"

#include <iostream>


General::General()
{
	windows.create(sf::VideoMode(static_cast<int> (windowsWidth), static_cast<int>(windowsHeight)), windowsName, sf::Style::Close);
	windows.setVerticalSyncEnabled(true);

}

General::~General()
{
}

void General::run()
{
	startmap();

	while (windows.isOpen())
	{
		while (windows.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				windows.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { windows.close(); break; }

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
				{ 
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ruch(3);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ruch(4);
					ruch(1); 
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { ruch(2); break; }
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { ruch(3); break; }
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { ruch(4); break; }

				break;
			default:
				break;
			}

		}

		fizyka();
		draw();
		//std::cout << "test" << std::endl;
	}
}

void General::startmap()
{
	int level[] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};

	if (!map.load("Texture\\Textur.png", sf::Vector2u(40, 40), level, 20, 14))
		windows.close();

	postac();

}

void General::postac()
{
	// wczytanie textur
	if (!texturepostac.loadFromFile("Texture\\Postac.png"))
		std::cout << "Erroe: load postac\n";

	// rysowanie postaci
	spritepostac.setTexture(texturepostac);
	spritepostac.setTextureRect(sf::IntRect(0, 0, 40, 120));

	// wyznaczanie position
	//positionpostacx = 1;
	//positionpostacy = 1;
	spritepostac.setPosition(0, kolizja - wysokoscpostaci);
}