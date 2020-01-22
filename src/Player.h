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
    /**
     * Construct a player
     * @param game pointer to Game
     */
    Player(Game *game) : game(game) {mCollidable = true;}

    /**
    * Handle a collision with the given game object
    * @param obj object that a collision occured with
    */
    void handleCollision(GameObject *obj) override;

    /**
     * Updates the player's position and velocity
     * @param elapsed time elapsed since last frame
     */
    void update(const double &elapsed) override;
};


#endif //ARKEKNOID_CPP_PLAYER_H
