#include "SteelEngine.h"

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include <vector>

namespace steel
{
	Engine::Engine() : 
		window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), 
			"Steel Engine", sf::Style::Default)
	{};

	void Engine::start()
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
			draw();
		}
	}

	void Engine::input()
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
				window.close();
			}
			default:
			{
				break;
			}
		}

		//Update button color
		for (Button &currentButton : buttons)
		{
			currentButton.updateButton(sf::Mouse::getPosition(window));
		}

	}


	void Engine::draw()
	{
		// Clear the last frame
		window.clear(sf::Color(255, 255, 255));

		for (GraphicsObject &currentObject : objects)
		{
			currentObject.displayObject(window);
		}

		for (Button &currentButton : buttons)
		{
			currentButton.displayButton(window);
		}

		// Show everything drawn
		window.display();
	};

	void Engine::addObjects(std::vector<GraphicsObject>& _objects)
	{
		objects = _objects;
	}

	void Engine::addButtons(std::vector<Button> &_buttons)
	{
		buttons = _buttons;
	}

}

