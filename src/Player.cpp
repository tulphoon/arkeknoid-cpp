//
// Created by Dawid Osuchowski on 25/12/2019.
//

#include <SDL_log.h>
#include "Player.h"

void Player::update(const double &elapsed) {

    // Input check
    if(game->keyPressed[SDL_SCANCODE_A] || game->keyPressed[SDL_SCANCODE_LEFT]) {
        mPos -= mVel * elapsed;

        // Boundary check
        if(left() <= 0) {
            mPos.setX(0);
        }
    } else if (game->keyPressed[SDL_SCANCODE_D] || game->keyPressed[SDL_SCANCODE_RIGHT]) {
        mPos += mVel * elapsed;

        // Boundary check
        if(right() >= game->getWindowWidth()) {
            mPos.setX(game->getWindowWidth() - width());
        }
    }

    // Update the rect position in preparation for rendering
    mRect.x = mPos.getX();
    mRect.y = mPos.getY();
}

void Player::handleCollision(GameObject *obj) {
    // A collision does not have an effect on the player, so empty
}
