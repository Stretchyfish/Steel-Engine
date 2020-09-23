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

		project = Button(sf::Vector2f(100.f, 20.f), sf::Color(128, 128, 128), sf::Vector2f(0, 0), font, "Project");
		settings = Button(sf::Vector2f(100.f, 20.f), sf::Color(128, 128, 128), sf::Vector2f(100.f, 0), font, "Settings");
		
		topBar = sf::RectangleShape(sf::Vector2f(_window.getSize().x,20.f));
		topBar.setOutlineColor(sf::Color(0,0,0));
		topBar.setOutlineThickness(2.f);

		topBar.setFillColor(sf::Color(128, 128, 128));

		objects = sf::RectangleShape(sf::Vector2f(_window.getSize().x / 2.5f, _window.getSize().y / 2));
		objects.setPosition(sf::Vector2f(0, 22.f));
		objects.setFillColor(sf::Color(128,128,128));
		objects.setOutlineColor(sf::Color(0,0,0));
		objects.setOutlineThickness(2.f);

		objectPanel = sf::RectangleShape(sf::Vector2f(_window.getSize().x, _window.getSize().y / 2 - 20.f));
		objectPanel.setPosition(sf::Vector2f(0, objects.getSize().y));
		objectPanel.setFillColor(sf::Color(128,128,128));
		objectPanel.setOutlineColor(sf::Color(0,0,0));
		objectPanel.setOutlineThickness(2.f);

		Engine_Text = sf::Text("Engine", font);
		Engine_Text.setCharacterSize(128);
		Engine_Text.setFillColor(sf::Color::White);

		Engine_Text.setPosition(sf::Vector2f(850.f, 120.f));
	}

	void updateGUI(sf::Vector2i mousePosition)
	{
		project.updateButton(mousePosition);
		settings.updateButton(mousePosition);
	}

	void drawGUI(sf::RenderWindow &_window)
	{
		_window.draw(topBar);
		_window.draw(objects);
		_window.draw(objectPanel);
		_window.draw(Engine_Text);
		project.drawButton(_window);
		settings.drawButton(_window);
	}

private:
	sf::RectangleShape topBar;
	Button project;
	Button settings;
	sf::Font font;

	sf::Text Engine_Text;
	sf::RectangleShape objects;
	sf::RectangleShape objectPanel;
	sf::RectangleShape world;
};

