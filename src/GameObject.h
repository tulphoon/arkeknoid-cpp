//
// Created by Dawid Osuchowski on 25/12/2019.
//

#ifndef ARKEKNOID_CPP_GAMEOBJECT_H
#define ARKEKNOID_CPP_GAMEOBJECT_H


#include <SDL_rect.h>
#include "Vec2D.h"

class GameObject {
    Vec2D mPos;
    Vec2D mVel;
    SDL_Rect mRect;
    SDL_Color mColor;
    int mSpeed;
public:
    virtual ~GameObject() = default;
    virtual void update() = 0;


};


#endif //ARKEKNOID_CPP_GAMEOBJECT_H
