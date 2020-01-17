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

/**
 * @class GameObject
 * @brief An abstract class which is a base for all objects in the game
 */

class GameObject {
protected:
    Vec2D mPos;
    Vec2D mVel;
    SDL_Rect mRect;
    SDL_Color mColor;
    bool mCollidable;
public:
    virtual ~GameObject() = default;
    virtual void update(const double &elapsed) = 0;
    virtual void render(SDL_Renderer* renderer);

    /// Handle collision between the game objects and another game object
    virtual void handleCollision(GameObject *obj) = 0;

    const Vec2D &getPos() const;

    void setPos(const Vec2D &mPos);

    const Vec2D &getVel() const;

    void setVel(const Vec2D &mVel);

    const SDL_Rect &getRect() const;

    void setRect(const SDL_Rect &mRect);

    const SDL_Color &getColor() const;

    void setColor(const SDL_Color &mColor);

    /// Return x coordinate for left side of the object
    float left();

    /// Return x coordinate for right side of the object
    float right();

    /// Return y coordinate for top side of the object
    float top();

    /// Return y coordinate for bottom side of the object
    float bottom();

    /// Return object's width
    int width();

    /// Return object's height
    int height();

    /// Checks for collision between objects
    bool isColliding(GameObject *obj);
};


#endif //ARKEKNOID_CPP_GAMEOBJECT_H
