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
				if (sf::Keyboard::Escape) { windows.close(); break; }

			default:
				break;
			}
		}
		draw();
		//std::cout << "test" << std::endl;
	}
}

void General::draw()
{
	windows.clear();
	windows.draw(map);
	windows.display();
}

void General::startmap()
{
	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};

	if (!map.load("Texture\\Textur.png", sf::Vector2u(40, 40), level, 16, 8))
		windows.close();
}