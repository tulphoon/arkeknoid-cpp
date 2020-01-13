//
// Created by Dawid Osuchowski on 25/12/2019.
//

#include "GameObject.h"

void GameObject::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, mColor.r, mColor.g, mColor.b, 255);
    SDL_RenderFillRect(renderer, &mRect);
}

const Vec2D &GameObject::getPos() const {
    return mPos;
}

void GameObject::setPos(const Vec2D &mPos) {
    GameObject::mPos = mPos;
}

const Vec2D &GameObject::getVel() const {
    return mVel;
}

void GameObject::setVel(const Vec2D &mVel) {
    GameObject::mVel = mVel;
}

const SDL_Rect &GameObject::getRect() const {
    return mRect;
}

void GameObject::setRect(const SDL_Rect &mRect) {
    GameObject::mRect = mRect;
}

const SDL_Color &GameObject::getColor() const {
    return mColor;
}

void GameObject::setColor(const SDL_Color &mColor) {
    GameObject::mColor = mColor;
}

float GameObject::left() {
    return mPos.getX();
}

float GameObject::right() {
    return left() + mRect.w;
}

float GameObject::top() {
    return mPos.getY();
}

float GameObject::bottom() {
    return top() + mRect.h;
}

int GameObject::width() {
    return mRect.w;
}

int GameObject::height() {
    return mRect.h;
}

bool GameObject::isColliding(GameObject *obj) {
    if (right() < obj->left() || left() > obj->right()) return false;
    if (bottom() < obj->top() || top() > obj->bottom()) return false;

    return true;
}