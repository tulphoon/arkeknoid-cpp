//
// Created by Dawid Osuchowski on 04/01/2020.
//

#ifndef ARKEKNOID_CPP_BALL_H
#define ARKEKNOID_CPP_BALL_H

#include <iostream>
#include "GameObject.h"
#include "Game.h"

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
    Ball(Game *game) : game(game) {mCollidable = true;}

    void update(const double &elapsed) override;

    void handleCollision(GameObject *obj) override;

    int getSpeed() const;

    void setSpeed(int speed);
};


#endif //ARKEKNOID_CPP_BALL_H
