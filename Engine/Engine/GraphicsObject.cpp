#include "SteelEngine.h"

namespace steel
{
	GraphicsObject::GraphicsObject() :
		squareShape()
	{

	}

	GraphicsObject::GraphicsObject(int type)
	{
		switch(type)
		{
			case 1 :
				squareShape = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
				squareShape.setFillColor(sf::Color(194,194,194));
				break;
			case 2 :
				circleShape = sf::CircleShape(90);
				circleShape.setFillColor(sf::Color(90,90,90));
				break;

			default:
			break;
		}
	}

	void GraphicsObject::createSquare()
	{
		squareShape = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
	}

	void GraphicsObject::changeColor()
	{
		squareShape.setFillColor(sf::Color(0, 0, 0));
		circleShape.setFillColor(sf::Color(90, 90, 90));
	}

	void GraphicsObject::displayObject(sf::RenderWindow &_window)
	{
		_window.draw(squareShape);
		_window.draw(circleShape);
	}

}