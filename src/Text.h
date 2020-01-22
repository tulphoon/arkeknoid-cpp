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


/**
 * @class Text
 * @brief Represents a text
 */
class Text : public GameObject {
    Game *game;

    std::string mString;
    TTF_Font* mFont;
public:
    /**
     * Construct a Text
     * @param game pointer to Game
     * @param mString text to be displayed
     * @param mFont font to be used in the text
     */
    Text(Game *game, const std::string &mString, TTF_Font *mFont) : game(game), mString(mString), mFont(mFont) {mCollidable = false;}

    /**
     * Text doesn't need updating so not used
     * @param elapsed
     */
    void update(const double &elapsed) override;

    /**
     * Render the Text on the screen
     * @param renderer
     */
    void render(SDL_Renderer* renderer) override;

    /**
     * Text does not handle collisions with any objects
     * @param obj
     */
    void handleCollision(GameObject *obj) override;

    /**
     * Set the text string
     * @param mString string to be set
     */
    void setString(const std::string &mString);
};


#endif //ARKEKNOID_CPP_TEXT_H
