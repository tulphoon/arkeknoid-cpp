//
// Created by Dawid Osuchowski on 04/01/2020.
//

#ifndef ARKEKNOID_CPP_BALL_H
#define ARKEKNOID_CPP_BALL_H


#include "GameObject.h"
#include "Game.h"

class Ball : public GameObject {
    Game *game;
public:
    Ball(Game *game) : game(game) {}

    void update(const double &elapsed);
};


#endif //ARKEKNOID_CPP_BALL_H
