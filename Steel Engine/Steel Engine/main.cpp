#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include <iostream>

#include "SteelEngine.h"
#include "Gameobject.h"

int main()
{
    SteelEngine engine;

    Gameobject logo("Steel.png");
    std::vector<Gameobject> objects
    {
        logo
    };

    engine.start(objects);

    return 0;
}