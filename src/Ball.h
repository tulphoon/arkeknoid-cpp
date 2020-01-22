//
// Created by Dawid Osuchowski on 04/01/2020.
//

#ifndef ARKEKNOID_CPP_BALL_H
#define ARKEKNOID_CPP_BALL_H

#include <iostream>
#include "GameObject.h"
#include "Game.h"

/**
 * State of the ball
 */
enum BallState {
    BALL_LOSE,
    BALL_MOVING
};

/**
 * @class Ball
 * @brief Represents the ball
 */

class Ball : public GameObject {
    Game *game;
    BallState mBallState = BALL_MOVING;
    int speed = 300;
public:
    /**
     * Constructor of ball
     * @param game pointer to Game
     */
    Ball(Game *game) : game(game) {mCollidable = true;}

    /**
     * Updates the ball position and velocity
     * @param elapsed time elapsed since last frame
     */
    void update(const double &elapsed) override;

    /**
     * Handle a collision with the given game object
     * @param obj object that a collision occured with
     */
    void handleCollision(GameObject *obj) override;

    int getSpeed() const;

    void setSpeed(int speed);
};


#endif //ARKEKNOID_CPP_BALL_H
