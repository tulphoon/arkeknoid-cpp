//
// Created by Dawid Osuchowski on 25/12/2019.
//

#include <SDL_log.h>
#include "Player.h"

void Player::update(const double &elapsed) {

    // Input check
    if(game->keyPressed[SDL_SCANCODE_A]) {
        mPos -= mVel * elapsed;

        // Boundary check
        if(left() <= 0) {
            mPos.setX(0);
        }
    } else if (game->keyPressed[SDL_SCANCODE_D]) {
        mPos += mVel * elapsed;

        // Boundary check
        if(right() >= game->getWindowWidth()) {
            mPos.setX(game->getWindowWidth() - width());
        }
    }

    mRect.x = mPos.getX();
    mRect.y = mPos.getY();
}

void Player::handleCollision(GameObject *obj) {

}
