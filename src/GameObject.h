//
// Created by Dawid Osuchowski on 25/12/2019.
//

#ifndef ARKEKNOID_CPP_GAMEOBJECT_H
#define ARKEKNOID_CPP_GAMEOBJECT_H


#include <SDL_rect.h>
#include "Vec2D.h"

class GameObject {
    Vec2D pos;
    Vec2D vel;
    SDL_Rect rect;
    int speed;
};


#endif //ARKEKNOID_CPP_GAMEOBJECT_H
