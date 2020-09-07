//
// Created by willi on 28.08.20.
//
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ostream>

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

class Player {
public:

    Player(const std::string &name, const std::vector<sf::Keyboard::Key> &keys, const sf::Color &color);

    const std::string &getName() const;

    void setName(const std::string &name);


    const sf::Color &getColor() const;

    void setColor(const sf::Color &color);

    const std::vector<sf::Keyboard::Key> &getKeys() const;

    void setKeys(const std::vector<sf::Keyboard::Key> &keys);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

private:

    std::string name;
    std::vector<sf::Keyboard::Key> keys;
    sf::Color color;






};
#endif //UNTITLED_PLAYER_H
