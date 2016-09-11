#pragma once

#include <SFML\Graphics.hpp>

class LoadMap : public sf::Drawable, public sf::Transformable
{
public:

	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
	{
		// wczytanie atlasu tekstur
		if (!m_tileset.loadFromFile(tileset))
			return false;

		// zmiana rozmiaru tablicy, tak aby pasowa³a do wielkoœci mapy
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(width * height * 4);

		// zape³nianie vertex array, po jednym na kafel
		for (unsigned int i = 0; i < width; ++i)
			for (unsigned int j = 0; j < height; ++j)
			{
				// pobranie obecnego numeru kafla
				int tileNumber = tiles[i + j * width];

				// znalezienie jego pozycji na tileset
				int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
				int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

				// pobranie wskaŸnika do bie¿¹cego kafla czworok¹ta
				sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

				// ustawienie 4 rogów
				quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
				quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
				quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
				quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

				// ustawienie 4 wspó³rzêdnych tekstury
				quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			}

		return true;
	}

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// ustawienie przekszta³ceñ
		states.transform *= getTransform();

		// ustawienie tekstury
		states.texture = &m_tileset;

		// narysowanie
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};
