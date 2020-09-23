#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include <string>
#include <fstream>
#include <vector>

#include "Gameobject.h"
#include "GUI.h"

class SteelEngine
{
public:
	SteelEngine() : window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Steel Engine", sf::Style::Default), gui(window), character("Steel.png")
	{
		//Open settings file
		std::ifstream settingsFile("settings.txt");
		if (settingsFile.good())
		{
			std::string width;
			std::string height;
			settingsFile >> width >> width;
			settingsFile >> height >> height;
			std::cout << "Width : " << width << std::endl;
			std::cout << "Height : " << height << std::endl;
			window.setSize(sf::Vector2u(std::stoi(width), std::stoi(height)));
		}

		//Gameobject logo;
		//logo.setSprite("Steel.png");
		//logo.setPosition(sf::Vector2f(700, 120));

	}

	void start(std::vector<Gameobject> &array)
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
			draw(array);
		}
	}

	void input()
	{
		window.pollEvent(event);

		switch (event.type)
		{
			case sf::Event::Resized:
			{
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
				break;
			}
			case sf::Event::Closed:
			{
				std::cout << "Window X size" << window.getSize().x << std::endl;
				std::cout << "Window Y size" << window.getSize().y << std::endl;

				//Create a file to save settings
				std::ofstream settingsFile{ "settings.txt" };
				std::string text = "hejmeddigminven";
				settingsFile << "Height " << window.getSize().x << "\n";
				settingsFile << "Width " << window.getSize().y << "\n";
				settingsFile.close();

				window.close();
			}
			default:
			{
				break;
			}
		}

		gui.updateGUI(sf::Mouse::getPosition(window));
	}

	void update(float deltaTime)
	{
		
	}

	void draw(std::vector<Gameobject> &array)
	{
		// Clear the last frame
		window.clear(sf::Color(192, 192, 192));

		for (Gameobject &currentObject : array)
		{
			window.draw(currentObject.getSprite());
		}

		//window.draw(character.getSprite());

		gui.drawGUI(window);

		// Show everything drawn
		window.display();
	}


private:
	sf::RenderWindow window;
	sf::Event event;

	GUI gui;
	std::vector<Gameobject> objectArray = {};
	Gameobject character;

	std::fstream settings;

	bool fileExist(std::string filename)
	{
		std::ifstream file(filename);
		return file.good();
	}

};

