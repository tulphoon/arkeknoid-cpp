//
// Created by Dawid Osuchowski on 04/01/2020.
//

#include "Ball.h"

void Ball::update(const double &elapsed) {
    switch(mBallState) {
        case BALL_LOSE:
            game->setGameState(STATE_GAMEOVER);
            break;
        case BALL_MOVING:

            // Increase ball speed every second
            if(game->ballCurrentIncreaseSpeedTime > game->ballLastIncreaseSpeedTime + 1000) {
                speed += 10;

                game->ballLastIncreaseSpeedTime = game->ballCurrentIncreaseSpeedTime;
            }

            // Move the ball
            mPos += mVel.normalized() * speed * elapsed;


            // Check for collisions between the ball and the boundaries of the window
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
                // Ball falls to the bottom of the screen
                mBallState = BALL_LOSE;
            }
            break;
    }


    // Update the rect position in preparation for rendering
    mRect.x = mPos.getX();
    mRect.y = mPos.getY();
}

int Ball::getSpeed() const {
    return speed;
}

void Ball::setSpeed(int speed) {
    Ball::speed = speed;
}

void Ball::handleCollision(GameObject *obj) {
    // From top
    if(bottom() >= obj->top()) {
        mVel.setY(-mVel.getY());
        mPos.setY(obj->top() - height());
    }
}
