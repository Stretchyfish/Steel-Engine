#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include "Button.h"

class GUI
{
public:
	GUI(sf::RenderWindow &_window) : font()
	{
		if (!font.loadFromFile("Roboto-Light.ttf"))
		{
			//error
		}

		settings = Button(sf::Vector2f(100.f, 20.f), sf::Color(128, 128, 128), sf::Vector2f(0, 0), font, "Project");
		topBar = sf::RectangleShape(sf::Vector2f(_window.getSize().x,20.f));
		topBar.setFillColor(sf::Color(128, 128, 128));
	}

	void updateGUI(sf::Vector2i mousePosition)
	{
		settings.updateButton(mousePosition);
	}

	void drawGUI(sf::RenderWindow &_window)
	{
		_window.draw(topBar);
		settings.drawButton(_window);
	}

private:
	sf::RectangleShape topBar;
	Button settings;
	sf::Font font;
};

