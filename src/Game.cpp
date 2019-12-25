//
// Created by Dawid Osuchowski on 21/12/2019.
//

#include "Game.h"

#include <SDL.h>

Game::Game(const std::string& windowTitle, const int& windowWidth, const int& windowHeight) : mWindowWidth(windowWidth), mWindowHeight(windowHeight) {
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
    }

    // create a window
    mWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWindowWidth, mWindowHeight, SDL_WINDOW_SHOWN);

    if(mWindow == nullptr) {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
    }

    // create a renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    if(mRenderer == nullptr) {
        SDL_Log("Could not create renderer: %s\n", SDL_GetError());
    }
}

Game::~Game() {
    // destroy window
    SDL_DestroyWindow(mWindow);

    // deactivate subsystems and quit SDL
    TTF_Quit();
    SDL_Quit();

}

void Game::run() {
    // Run game loop
    while (mGameState != STATE_EXIT) {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents() {
    while(SDL_PollEvent(&mEvent)) {
        switch (mEvent.type) {
            case SDL_QUIT:
                mGameState = STATE_EXIT;
                break;
        }
    }
}

SDL_Renderer *Game::getRenderer() const {
    return mRenderer;
}

void Game::update() {

}

void Game::render() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
    SDL_RenderPresent(mRenderer);
}
