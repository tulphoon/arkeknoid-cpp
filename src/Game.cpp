//
// Created by Dawid Osuchowski on 21/12/2019.
//

#include "Game.h"

#include <SDL.h>

Game::Game() {
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
//        return 1;
    }

    // create a window
    mWindow = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    if(mWindow == nullptr) {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
//        return 1;
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
    SDL_Quit();

}

void Game::loop() {


    // Run game loop
    while (mGameState != STATE_EXIT) {
        this->handleEvents();


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
