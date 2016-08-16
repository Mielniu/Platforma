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
		std::cout << "test" << std::endl;
	}
}