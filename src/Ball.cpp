//
// Created by Dawid Osuchowski on 04/01/2020.
//

#include "Ball.h"

void Ball::update(const double &elapsed) {

    switch(mBallState) {
        case BALL_LOSE:
            std::cout << "YOU LOST! Thanks for playing!" << std::endl;
            game->setGameState(STATE_EXIT);
            break;
        case BALL_MOVING:
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
                mBallState = BALL_LOSE;

            }
            break;
    }

    mRect.x = mPos.getX();
    mRect.y = mPos.getY();
}

void Ball::handleCollision(GameObject *obj) {
    // From top
    if(bottom() >= obj->top()) {
        mVel.setY(-mVel.getY());
        mPos.setY(obj->top() - height());
    }
}
