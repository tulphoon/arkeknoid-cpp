//
// Created by Dawid Osuchowski on 25/12/2019.
//

#ifndef ARKEKNOID_CPP_PLAYER_H
#define ARKEKNOID_CPP_PLAYER_H


#include "GameObject.h"
#include "Game.h"

/**
 * @class Player
 * @brief Represents the player
 */

class Player : public GameObject {
    Game *game;
public:
    Player(Game *game) : game(game) {mCollidable = true;}

    void handleCollision(GameObject *obj) override;

    void update(const double &elapsed) override;
};


#endif //ARKEKNOID_CPP_PLAYER_H
