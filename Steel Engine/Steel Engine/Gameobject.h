#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include <string>

class Gameobject
{
public:
	Gameobject() : position() , sprite(), texture()
	{

	}
	
	Gameobject(std::string fileName) : position() , sprite(), texture()
	{
		if (texture.loadFromFile("Steel.png"))
		{
			sprite.setTexture(texture);
			sprite.setPosition(sf::Vector2f(700.f, 120.f));
			sprite.setScale(sf::Vector2f(1.f, 1.f));
		}
	}

	Gameobject(std::string fileName, sf::Vector2f _position) : sprite(), position(_position), texture()
	{
		if (texture.loadFromFile(fileName))
		{
			sprite.setTexture(texture);
			sprite.setPosition(sf::Vector2f(700.f, 120.f));
			sprite.setScale(sf::Vector2f(1.f, 1.f));
		}

		sprite.setPosition(_position);
		position = _position;
	}

	void setSprite(std::string fileName)
	{
		if (texture.loadFromFile(fileName))
		{
			sprite.setTexture(texture);
		}
	}

	void setPosition(sf::Vector2f _position)
	{
		position = _position;
		sprite.setPosition(_position);
	}

	sf::Sprite &getSprite()
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

