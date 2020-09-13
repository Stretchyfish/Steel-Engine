#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

class Gameobject
{
public:
	Gameobject()
	{
		texture.loadFromFile("Steel.png");
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(900.f, 170.f));
		sprite.setScale(sf::Vector2f(1.f, 1.f));
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

