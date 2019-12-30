//
// Created by Dawid Osuchowski on 21/12/2019.
//

#ifndef ARKEKNOID_CPP_GAME_H
#define ARKEKNOID_CPP_GAME_H


#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include "GameObject.h"

enum State {
    STATE_MENU,
    STATE_PLAYING,
    STATE_PAUSE,
    STATE_EXIT
};

class Game {
    SDL_Window* mWindow = nullptr;
    int mWindowWidth, mWindowHeight;
    SDL_Renderer* mRenderer = nullptr;
    State mGameState = STATE_MENU;
    SDL_Event mEvent;

    std::vector<GameObject*> mGameObjects;

    void handleEvents();
    void update(const double &elapsed);
    void render();

public:
    Game(const std::string& windowTitle, const int& windowWidth, const int& windowHeight);

    ~Game();

    void run();

    SDL_Renderer *getRenderer() const;
};


#endif //ARKEKNOID_CPP_GAME_H
