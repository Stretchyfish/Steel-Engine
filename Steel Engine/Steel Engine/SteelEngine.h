#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include "Gameobject.h"
#include "GUI.h"

class SteelEngine
{
public:
	SteelEngine() : window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Steel Engine", sf::Style::Default), gui(window)
	{
	}

	void start()
	{
		sf::Clock clock;
		sf::Event event;

		while (window.isOpen())
		{
			// Restart the clock and save the elapsed time into dt
			sf::Time delta = clock.restart();

			// Make a fraction from the delta time
			float deltaTime = delta.asSeconds();

			input();
			update(deltaTime);
			draw();
		}
	}

	void input()
	{
		window.pollEvent(event);

		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
		default:
			break;
		}

		gui.updateGUI(sf::Mouse::getPosition(window));
	}

	void update(float dtAsSeconds)
	{
		
	}

	void draw()
	{
		// Clear the last frame
		window.clear(sf::Color(192, 192, 192));

		window.draw(character.getSprite());
		gui.drawGUI(window);

		// Show everything drawn
		window.display();
	}


private:
	sf::RenderWindow window;
	sf::Event event;

	GUI gui;
	Gameobject character;
};

