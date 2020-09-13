#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>
#include <SFML/System.hpp>

#include <string>

class Button
{
public:

	Button()
	{

	}

	Button(sf::Vector2f _size, sf::Color _color, sf::Vector2f _position, sf::Font &_font, std::string _text)
	{
		size = _size;
		color = _color;
		position = _position;

		shape = sf::RectangleShape(_size);
		shape.setFillColor(color);
		shape.setPosition(_position);

		text = sf::Text(_text, _font);
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);
		text.setCharacterSize(16);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(position.x + size.x / 2, position.y + size.y));
	}

	void drawButton(sf::RenderWindow &window)
	{
		window.draw(shape);
		window.draw(text);
	}

	void updateButton(sf::Vector2i mousePosition)
	{
		if (checkMouseOver(mousePosition))
		{
			shape.setFillColor(sf::Color(color.r + 20, color.g + 20, color.b + 20));
		}
		else
		{
			shape.setFillColor(color);
		}
	}

	bool checkMouseOver(sf::Vector2i mousePosition)
	{
		if (position.x < mousePosition.x && mousePosition.x <= position.x + size.x
			&& position.y < mousePosition.y && mousePosition.y < position.y + size.y)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

private:
	sf::RectangleShape shape;
	sf::Vector2f size;
	sf::Color color;
	sf::Vector2f position;
	sf::Text text;

};

