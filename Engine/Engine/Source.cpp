#include "SteelEngine.h"

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include <vector>

int main()
{
	sf::Font robot;
	if (!robot.loadFromFile("Roboto-Light.ttf"))
	{
		//error
	}

	steel::Engine engine;

	//Button objects
	steel::Button knap(100.f, 20.f, steel::Color(128, 128, 128), steel::Point(100,100), "Roboto-Light.ttf", "Project");
	std::vector<steel::Button> buttonList
	{
		knap
	};
	engine.addButtons(buttonList);

	//Graphics objects
	steel::GraphicsObject box;
	box.createSquare();
	box.changeColor();

	steel::GraphicsObject newSquare(steel::square);

	steel::GraphicsObject bigBox;
	bigBox.createSquare();

	steel::GraphicsObject biggerBox;
	biggerBox.createSquare();

	steel::GraphicsObject firstCircle(steel::circle);

	std::vector<steel::GraphicsObject> list
	{
		box,
		firstCircle
	};

	engine.addObjects(list);

	engine.start();


	return 0;
}