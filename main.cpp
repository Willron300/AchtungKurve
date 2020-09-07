#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "include/menu/config.h"
#include "include/menu/window.h"
#include "src/game/GameWindow.h"

int main()
{
    //int test = MenuWindow::menu();
    int test = GameWindow::game();
}

/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Achtung Kurve!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
*/