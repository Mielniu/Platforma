#include "General.h"
#include "LoadTextur.h"

#include <iostream>

Texture www;

General::General()
{
	windows.create(sf::VideoMode(static_cast<int> (windowsWidth), static_cast<int>(windowsHeight)), windowsName, sf::Style::Close);
	windows.setVerticalSyncEnabled(true);
	www.load();
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
		draw();
		//std::cout << "test" << std::endl;
	}
}

void General::draw()
{
	windows.clear();
	windows.draw(www.id[0]);
	windows.draw(www.id[1]);
	windows.draw(www.id[2]);
	windows.draw(www.id[3]);
	windows.draw(www.catcat);
	windows.display();
}