//
// Created by Dawid Osuchowski on 04/01/2020.
//

#include "Ball.h"

void Ball::update(const double &elapsed) {
    mPos += mVel * elapsed;

    if(left() <= 0) {
        mPos.setX(0);
        mVel.setX(-mVel.getX());
    } else if (right() >= game->getWindowWidth()) {
        mPos.setX(game->getWindowWidth() - width());
        mVel.setX(-mVel.getX());
    }

    if(top() <= 0) {
        mPos.setY(0);
        mVel.setY(-mVel.getY());
    } else if(bottom() >= game->getWindowHeight()) {
        mPos.setY(game->getWindowHeight() - height());
        mVel.setY(-mVel.getY());
    }

    mRect.x = mPos.getX();
    mRect.y = mPos.getY();
}
