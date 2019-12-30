//
// Created by Dawid Osuchowski on 25/12/2019.
//

#include <SDL_log.h>
#include "Player.h"

void Player::update(const double &elapsed) {
    mPos += mVel * elapsed;

    mRect.x = mPos.getX();
    mRect.y = mPos.getY();
}
