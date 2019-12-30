//
// Created by Dawid Osuchowski on 25/12/2019.
//

#ifndef ARKEKNOID_CPP_PLAYER_H
#define ARKEKNOID_CPP_PLAYER_H


#include "GameObject.h"

enum PlayerState {
    PLAYER_STATIONARY,
    PLAYER_MOVING
};

class Player : public GameObject {
public:
    void update(const double &elapsed);
};


#endif //ARKEKNOID_CPP_PLAYER_H
