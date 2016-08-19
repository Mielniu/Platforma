#include "LoadTextur.h"

void Texture::load()
{
	if (!cat.loadFromFile("Texture\\Cat.png"))
	{
		std::cout << "Error: Load From File Cat" << std::endl;
	}

	if (!textur.loadFromFile("Texture\\Textur.png"))
	{
		std::cout << "Error: Load From File Texture" << std::endl;
	}
	loadSprite();
}

void Texture::loadSprite()
{
	id[0].setTexture(textur);
	id[0].setTextureRect(sf::IntRect(0,0,40,40));

	id[1].setTexture(textur);
	id[1].setTextureRect(sf::IntRect(40, 0, 80, 40));
	id[1].setPosition(40, 0);

	id[2].setTexture(textur);
	id[2].setTextureRect(sf::IntRect(80, 0, 120, 40));
	id[2].setPosition(80, 0);

	id[3].setTexture(textur);
	id[3].setTextureRect(sf::IntRect(120, 0, 160, 40));
	id[3].setPosition(120, 0);

	catcat.setTexture(cat);
	catcat.setTextureRect(sf::IntRect(0, 0, 40, 40));
	catcat.setPosition(0, 40);

}