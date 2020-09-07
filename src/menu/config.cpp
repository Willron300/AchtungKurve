//
// Created by willi on 26.08.20.
//

#include "../../include/menu/config.h"


void Configuration::setCountPlayer(int countPlayer) {
    if (countPlayer < 1)
        return;
    Configuration::countPlayer = countPlayer;
}

void Configuration::setMode(Mode mode) {
    Configuration::mode = mode;
}

const Mode Configuration::getMode() const {
    return mode;
}

int Configuration::getCountPlayer() const {
    return countPlayer;
}

Configuration::Configuration() {
    mode = MClassic;
    countPlayer = 1;
}

const std::vector<Player> &Configuration::getPlayers() const {
    return players;
}

void Configuration::setPlayers(const std::vector<Player> &players) {
    Configuration::players = players;
}

std::ostream &operator<<(std::ostream &os, const Configuration &configuration) {
    os << "players: " << configuration.players.size() << " countPlayer: " << configuration.countPlayer << " mode: "
       << configuration.mode;
    return os;
}
