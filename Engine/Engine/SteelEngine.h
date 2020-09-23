#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include <vector>
#include <string>


namespace steel
{
	const int square = 1;
	const int circle = 2;

	class Color
	{
	public:
		Color(int _R, int _G, int _B);
		int R;
		int G;
		int B;
	private:
	};

	class Point
	{
	public:
		Point(int x, int y);
		int x;
		int y;
	private:
	};

	class Button
	{
	public:
		Button();
		Button(int width, int height, Color _color, Point _position, std::string _font, std::string _text);
		void displayButton(sf::RenderWindow& window);
		void updateButton(sf::Vector2i mousePosition);
	private:
		bool checkMouseOver(sf::Vector2i mousePosition);

		sf::RectangleShape shape;
		sf::Vector2f size;
		sf::Color color;
		sf::Vector2f position;
		sf::Text text;
		sf::Font font;
	};

	class GraphicsObject
	{
	public:
		GraphicsObject();
		GraphicsObject(int type);
		GraphicsObject(int type, Point Scalar);
		void createSquare();
		void changeColor();
		void displayObject(sf::RenderWindow& _window);

	private:
		sf::RectangleShape squareShape;
		sf::CircleShape circleShape;
		Button button;
	};

	class Engine
	{
	public:
		Engine();		//Setup engine (Default constructor)
		void start();	//Start Engine, will continously run
		void addObjects(std::vector<GraphicsObject> &_objects);
		void addButtons(std::vector<Button> &_buttons);

	private:
		void input();	//Update inputs
		void draw();	//Update graphic elements
		
		sf::RenderWindow window;	//Graphics window
		sf::Event event;			//Event/input tracker
		
		std::vector<GraphicsObject> objects;	//All objects to be displayed
		std::vector<Button> buttons;
	};



}