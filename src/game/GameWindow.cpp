//
// Created by willi on 02.09.20.
//

#include "GameWindow.h"
#include "../../include/menu/config.h"

int GameWindow::game()  {

    Configuration config = Configuration();

    sf::RenderWindow window(sf::VideoMode(1024, 622), "Achtung Kurve", sf::Style::Default);
    sf::Texture background;
    sf::Sprite backgroundImage;

    if (!background.loadFromFile("/home/willi/CLionProjects/untitled/doc/background.png"))
        std::cout << "Error: Could not display Alaskan Wilderness image" << std::endl;

    backgroundImage.setTexture(background);

    sf::RectangleShape rectBlack;
    rectBlack.setSize(sf::Vector2f(600, 400));
    rectBlack.setFillColor(sf::Color::Black);
    rectBlack.setOutlineColor(sf::Color::White);
    rectBlack.setOutlineThickness(5);
    rectBlack.setPosition(200,100);

    sf::CircleShape snake1 = sf::CircleShape(50,30);
    snake1.setFillColor(sf::Color::Green);
    snake1.setPosition(500,300);



    sf::Vector2<float> move = {0, 0};

    while (window.isOpen()){

        sf::Event evnt;

        while (window.pollEvent(evnt)){
            switch (evnt.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed: {
                    if (evnt.key.code == sf::Keyboard::A)
                        move = {-1, 0};
                    if (evnt.key.code == sf::Keyboard::W)
                        move = {0, -1};
                    if (evnt.key.code == sf::Keyboard::S)
                        move = {0, 1};
                    if (evnt.key.code == sf::Keyboard::D)
                        move = {1, 0};
                }
            }
        }
        snake1.move(move);
        window.clear();
        window.draw(backgroundImage);
        window.draw(rectBlack); //draw the sprite with blur shader
        window.draw(snake1);

        window.display();
    }
    return 0;
}