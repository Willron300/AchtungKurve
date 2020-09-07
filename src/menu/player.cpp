//
// Created by willi on 28.08.20.
//

#include <string>
#include <SFML/Graphics/Color.hpp>
#include "../../include/menu/player.h"

Player::Player(const std::string &name, const std::vector<sf::Keyboard::Key> &keys, const sf::Color &color) : name(
        name), keys(keys), color(color) {}

const std::string &Player::getName() const {
    return name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
}



const sf::Color &Player::getColor() const {
    return color;
}

void Player::setColor(const sf::Color &color) {
    Player::color = color;
}

const std::vector<sf::Keyboard::Key> &Player::getKeys() const {
    return keys;
}

void Player::setKeys(const std::vector<sf::Keyboard::Key> &keys) {
    Player::keys = keys;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "name: " << player.name << " keys: " << player.keys[0] << player.keys[1] << " color: " << player.color.toInteger();
    return os;
}


