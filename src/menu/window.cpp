//
// Created by willi on 26.08.20.
//
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "../../include/menu/config.h"
#include "../../include/menu/window.h"

int MenuWindow::menu() {

    Configuration config = Configuration();

    sf::RenderWindow window(sf::VideoMode(1024, 622), "Achtung Kurve", sf::Style::Default);
    sf::Texture background;
    sf::Sprite backgroundImage;

    if (!background.loadFromFile("/home/willi/CLionProjects/AchtungKurve/doc/background.png"))
        std::cout << "Error: Could not display Alaskan Wilderness image" << std::endl;

    backgroundImage.setTexture(background);

    sf::Font font;
    if (!font.loadFromFile("/home/willi/CLionProjects/AchtungKurve/doc/geekabyte2.ttf"))
        std::cout << "Can't find the font file" << std::endl;

    sf::Texture infoButton;
    sf::Sprite infoButtonImage;
    if (!infoButton.loadFromFile("/home/willi/CLionProjects/AchtungKurve/doc/info.png"))
        std::cout << "Can't find the image" << std::endl;
    infoButtonImage.setPosition(50.0f, 120.0f);
    infoButtonImage.setScale(0.01, 0.01);

    //float exitButtonWidth = infoButtonImage.getLocalBounds().width;
    //float exitButtonHeight = infoButtonImage.getLocalBounds().height;

    infoButtonImage.setTexture(infoButton);
    /*
    sf::Texture exitButton;
    sf::Sprite exitButtonImage;
    if ( !exitButton.loadFromFile( "/home/willi/CLionProjects/AchtungKurve/doc/button.png" ) )
        std::cout << "Can't find the image" << std::endl;
    exitButtonImage.setPosition( 50.0f, 500.0f );

    float exitButtonWidth = exitButtonImage.getLocalBounds().width;
    float exitButtonHeight = exitButtonImage.getLocalBounds().height;

    exitButtonImage.setTexture( exitButton );
    */
    sf::Text titleText;
    titleText.setFont(font);
    titleText.setStyle(sf::Text::Bold);
    titleText.setString("Achtung Kurve");
    titleText.setFillColor(sf::Color::Red);
    titleText.setCharacterSize(60);
    titleText.setPosition(200.0f, 0.0f);

    sf::Text modusText;
    modusText.setFont(font);
    modusText.setStyle(sf::Text::Bold);
    modusText.setString("Modus:");
    modusText.setFillColor(sf::Color::Green);
    modusText.setCharacterSize(40);
    modusText.setPosition(50.0f, 50.0f);

    sf::Text classicModusText;
    classicModusText.setFont(font);
    classicModusText.setStyle(sf::Text::Bold);
    classicModusText.setString("Classic");
    classicModusText.setFillColor(sf::Color(250, 20, 20));
    classicModusText.setCharacterSize(48);
    classicModusText.setPosition(80.0f, 100.0f);

    sf::Text classic2ModusText;
    classic2ModusText.setFont(font);
    classic2ModusText.setStyle(sf::Text::Bold);
    classic2ModusText.setString("Classic 2.0");
    classic2ModusText.setFillColor(sf::Color::White);
    classic2ModusText.setCharacterSize(48);
    classic2ModusText.setPosition(80.0f, 150.0f);


    sf::Text upgradeModusText;
    upgradeModusText.setFont(font);
    upgradeModusText.setStyle(sf::Text::Bold);
    upgradeModusText.setString("Upgrade");
    upgradeModusText.setFillColor(sf::Color::White);
    upgradeModusText.setCharacterSize(48);
    upgradeModusText.setPosition(80.0f, 200.0f);

    sf::Text playerText;
    playerText.setFont(font);
    playerText.setStyle(sf::Text::Bold);
    playerText.setString("Spieler:");
    playerText.setFillColor(sf::Color::Green);
    playerText.setCharacterSize(40);
    playerText.setPosition(50.0f, 250.0f);

    sf::Text playerCountText;
    playerCountText.setFont(font);
    playerCountText.setStyle(sf::Text::Bold);
    playerCountText.setString("Anzahl:");
    playerCountText.setFillColor(sf::Color::Green);
    playerCountText.setCharacterSize(40);
    playerCountText.setPosition(200.0f, 300.0f);

    sf::Text playerCountNumberText;
    playerCountNumberText.setFont(font);
    playerCountNumberText.setStyle(sf::Text::Bold);
    playerCountNumberText.setString(std::to_string(config.getCountPlayer()));
    playerCountNumberText.setFillColor(sf::Color::Green);
    playerCountNumberText.setCharacterSize(40);
    playerCountNumberText.setPosition(400.0f, 300.0f);

    sf::Text playerCountNumberPlusText;
    playerCountNumberPlusText.setFont(font);
    playerCountNumberPlusText.setStyle(sf::Text::Bold);
    playerCountNumberPlusText.setString("+");
    playerCountNumberPlusText.setFillColor(sf::Color::Green);
    playerCountNumberPlusText.setCharacterSize(40);
    playerCountNumberPlusText.setPosition(450.0f, 280.0f);

    sf::Text playerCountNumberMinusText;
    playerCountNumberMinusText.setFont(font);
    playerCountNumberMinusText.setStyle(sf::Text::Bold);
    playerCountNumberMinusText.setString("-");
    playerCountNumberMinusText.setFillColor(sf::Color::Green);
    playerCountNumberMinusText.setCharacterSize(40);
    playerCountNumberMinusText.setPosition(450.0f, 320.0f);


    sf::Text playerNo1Text;
    playerNo1Text.setFont(font);
    playerNo1Text.setStyle(sf::Text::Bold);
    playerNo1Text.setString("Player 1    A und D");
    playerNo1Text.setFillColor(sf::Color::Black);
    playerNo1Text.setCharacterSize(40);
    playerNo1Text.setPosition(80.0f, 400.0f);

    sf::Text startText;
    startText.setFont(font);
    startText.setStyle(sf::Text::Bold);
    startText.setString("START");
    startText.setFillColor(sf::Color::Red);
    startText.setCharacterSize(90);
    startText.setPosition(350.0f, 500.0f);


    while (window.isOpen()) {
        sf::Event Event;
        while (window.pollEvent(Event)) {
            switch (Event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseMoved: {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ));
                    if (startText.getGlobalBounds().contains(mousePosF)) {

                        startText.setColor(sf::Color::Black);
                    } else {
                        startText.setColor(sf::Color::Red);
                    }
                    if (playerCountNumberPlusText.getGlobalBounds().contains(mousePosF)) {

                        playerCountNumberPlusText.setColor(sf::Color::Black);
                    } else {
                        playerCountNumberPlusText.setColor(sf::Color::Red);
                    }
                    if (playerCountNumberMinusText.getGlobalBounds().contains(mousePosF)) {

                        playerCountNumberMinusText.setColor(sf::Color::Black);
                    } else {
                        playerCountNumberMinusText.setColor(sf::Color::Red);
                    }
                    /*

                    if ( classic2ModusText.getGlobalBounds().contains( mousePosF ) )
                    {

                        classic2ModusText.setColor( sf::Color( 250, 20, 20 ) );
                    }
                    else
                    {
                        classic2ModusText.setColor( sf::Color::White);
                    }
                    if ( classicModusText.getGlobalBounds().contains( mousePosF ) )
                    {
                        classicModusText.setColor( sf::Color( 250, 20, 20 ) );
                    }
                    else
                    {
                        classicModusText.setColor( sf::Color::White);
                    }
                    if ( upgradeModusText.getGlobalBounds().contains( mousePosF ) )
                    {
                        upgradeModusText.setColor( sf::Color( 250, 20, 20 ) );
                    }
                    else
                    {
                        upgradeModusText.setColor( sf::Color::White);
                    }
                     */
                }
                    break;
                case sf::Event::MouseButtonPressed: {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ));
                    if (classic2ModusText.getGlobalBounds().contains(mousePosF)) {
                        classicModusText.setColor(sf::Color::White);
                        classic2ModusText.setColor(sf::Color(250, 20, 20));
                        upgradeModusText.setColor(sf::Color::White);
                        config.setMode(Mode::MClassic2);
                    }
                    if (classicModusText.getGlobalBounds().contains(mousePosF)) {
                        classic2ModusText.setColor(sf::Color::White);
                        classicModusText.setColor(sf::Color(250, 20, 20));
                        upgradeModusText.setColor(sf::Color::White);
                        config.setMode(Mode::MClassic);
                    }
                    if (upgradeModusText.getGlobalBounds().contains(mousePosF)) {
                        classicModusText.setColor(sf::Color::White);
                        upgradeModusText.setColor(sf::Color(250, 20, 20));
                        classic2ModusText.setColor(sf::Color::White);
                        config.setMode(Mode::MUpgrade);
                    }
                    if (playerCountNumberPlusText.getGlobalBounds().contains(mousePosF)) {
                        config.setCountPlayer(config.getCountPlayer() + 1);
                        playerCountNumberText.setString(std::to_string(config.getCountPlayer()));
                    }
                    if (playerCountNumberMinusText.getGlobalBounds().contains(mousePosF)) {
                        config.setCountPlayer(config.getCountPlayer() - 1);
                        playerCountNumberText.setString(std::to_string(config.getCountPlayer()));
                    }
                    if (startText.getGlobalBounds().contains(mousePosF)) {
                        printf("START\n");
                        std::cout << config << std::endl;
                    }

                }
                    break;
            }
        }

        window.clear();

        window.draw(backgroundImage);
        window.draw(infoButtonImage);
        window.draw(titleText);
        window.draw(modusText);
        window.draw(classicModusText);
        window.draw(classic2ModusText);
        window.draw(upgradeModusText);
        window.draw(playerText);
        window.draw(playerCountText);
        window.draw(playerCountNumberText);
        window.draw(playerCountNumberPlusText);
        window.draw(playerCountNumberMinusText);
        window.draw(playerNo1Text);
        window.draw(startText);
        window.display();
    }
    return 0;

};