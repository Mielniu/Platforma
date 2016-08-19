#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>

class Texture
{
public:
	void load();
	void loadSprite();
	
private:
	std::string loadCat = "Texture\Cat.png";
	std::string loadTexture = "Texture\texture.png";

	sf::Texture cat, textur;

public:
	sf::Sprite id[5];
	sf::Sprite catcat;
};