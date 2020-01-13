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

class Ball : public GameObject {
    Game *game;
    BallState mBallState = BALL_MOVING;
public:
    Ball(Game *game) : game(game) {}

    void update(const double &elapsed) override;

    void handleCollision(GameObject *obj) override;
};


#endif //ARKEKNOID_CPP_BALL_H
