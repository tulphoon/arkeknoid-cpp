//
// Created by Dawid Osuchowski on 16/01/2020.
//

#include "Text.h"

void Text::update(const double &elapsed) {
    return;
}

void Text::handleCollision(GameObject *obj) {
    return;
}

void Text::render(SDL_Renderer *renderer) {
    if(TTF_SizeText(mFont, mString.c_str(), &mRect.w, &mRect.h)) {
        SDL_Log("TTF_SizeText: %s\n", TTF_GetError());
        return;
    }

    // Create texture from surface
    SDL_Surface * surface = TTF_RenderText_Blended(mFont, mString.c_str(), mColor);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

    // Render texture on screen
    SDL_RenderCopy(renderer, texture, NULL, &mRect);

    // Free memory
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void Text::setString(const std::string &mString) {
    Text::mString = mString;
}
