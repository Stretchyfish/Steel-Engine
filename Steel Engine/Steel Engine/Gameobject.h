#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

class Gameobject
{
public:
	Gameobject()
	{
		texture.loadFromFile("character.png");
		sprite.setTexture(texture);
	}


	sf::Sprite getSprite()
	{
		return sprite;
	}

	void update(float _deltaTime)
	{
		sprite.setPosition(position);
	}

private:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;
};

