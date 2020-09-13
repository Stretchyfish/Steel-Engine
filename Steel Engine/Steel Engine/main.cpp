#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include <iostream>

#include "SteelEngine.h"

int main()
{
    std::cout << "Program turn on" << std::endl;
    SteelEngine engine;
    engine.start();

    return 0;
}