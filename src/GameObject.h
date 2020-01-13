//
// Created by Dawid Osuchowski on 25/12/2019.
//

#ifndef ARKEKNOID_CPP_GAMEOBJECT_H
#define ARKEKNOID_CPP_GAMEOBJECT_H


#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_scancode.h>
#include <unordered_map>
#include "Vec2D.h"

enum Type {
    TYPE_PLAYER,
    TYPE_BALL,
    TYPE_BLOCK
};

class GameObject {
protected:


    Vec2D mPos;
    Vec2D mVel;
    SDL_Rect mRect;
    SDL_Color mColor;
public:
    virtual ~GameObject() = default;
    virtual void update(const double &elapsed) = 0;
    virtual void render(SDL_Renderer* renderer);
    virtual void handleCollision(GameObject *obj) = 0;

    const Vec2D &getPos() const;

    void setPos(const Vec2D &mPos);

    const Vec2D &getVel() const;

    void setVel(const Vec2D &mVel);

    const SDL_Rect &getRect() const;

    void setRect(const SDL_Rect &mRect);

    const SDL_Color &getColor() const;

    void setColor(const SDL_Color &mColor);

    float left();
    float right();
    float top();
    float bottom();
    int width();
    int height();

    bool isColliding(GameObject *obj);
};


#endif //ARKEKNOID_CPP_GAMEOBJECT_H
