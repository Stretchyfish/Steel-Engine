#include "SteelEngine.h"

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include <vector>
#include <string>

namespace steel
{
	Button::Button(int width, int height, Color _color, Point _position, std::string _font, std::string _text)
	{
		if (!font.loadFromFile(_font))
		{
			//error
		}

		size = sf::Vector2f(width, height);
		color = sf::Color(_color.R, _color.G, _color.B);
		position = sf::Vector2f(_position.x, _position.y);

		shape = sf::RectangleShape(size);
		shape.setFillColor(color);
		shape.setPosition(position);

		text = sf::Text(_text, font);
		text.setCharacterSize(16);
		text.setFillColor(sf::Color::White);
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);

		text.setPosition(sf::Vector2f(position.x + size.x / 2.f, position.y + size.y / 2));
	}

	void Button::displayButton(sf::RenderWindow& window)
	{
		window.draw(shape);
		window.draw(text);
	};

	void Button::updateButton(sf::Vector2i mousePosition)
	{
		// If mouse hovers over button, change color
		if (checkMouseOver(mousePosition))
		{
			shape.setFillColor(sf::Color(color.r + 20, color.g + 20, color.b + 20));
		}
		else
		{
			shape.setFillColor(color);
		}
	}

	bool Button::checkMouseOver(sf::Vector2i mousePosition)
	{
		if (shape.getPosition().x < mousePosition.x && mousePosition.x <= shape.getPosition().x + shape.getSize().x
			&& shape.getPosition().y < mousePosition.y && mousePosition.y < shape.getPosition().y + shape.getSize().y)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	};

}