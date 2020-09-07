//
// Created by willi on 26.08.20.
//
#include <iostream>
#include "player.h"


#ifndef UNTITLED_CONFIG_H
#define UNTITLED_CONFIG_H

enum Mode : uint8_t {
    MClassic,
    MClassic2,
    MUpgrade,
};

class Configuration {
    std::vector<Player> players;
    int countPlayer;
    Mode mode;

public:
    Configuration();

    int getCountPlayer() const;
    const Mode getMode() const;
    void setCountPlayer(int countPlayer);
    void setMode(Mode mode);

    const std::vector<Player> &getPlayers() const;

    void setPlayers(const std::vector<Player> &players);

    friend std::ostream &operator<<(std::ostream &os, const Configuration &configuration);

private:




};


#endif //UNTITLED_CONFIG_H
