//
// Created by Dawid Osuchowski on 16/01/2020.
//

#ifndef ARKEKNOID_CPP_TEXT_H
#define ARKEKNOID_CPP_TEXT_H


#include <SDL_pixels.h>
#include <SDL_rect.h>
#include <string>
#include <SDL_ttf.h>
#include "GameObject.h"
#include "Game.h"

class Text : public GameObject {
    Game *game;

    std::string mString;
    TTF_Font* mFont;
public:
    Text(Game *game, const std::string &mString, TTF_Font *mFont) : game(game), mString(mString), mFont(mFont) {mCollidable = false;}

    void update(const double &elapsed) override;

    void render(SDL_Renderer* renderer) override;

    void handleCollision(GameObject *obj) override;

    void setString(const std::string &mString);
};


#endif //ARKEKNOID_CPP_TEXT_H
