//
// Created by Dawid Osuchowski on 21/12/2019.
//

#ifndef ARKEKNOID_CPP_GAME_H
#define ARKEKNOID_CPP_GAME_H


#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_events.h>

enum Side {
    RED,
    BLUE
};

enum State {
    STATE_MENU,
    STATE_PLAYING,
    STATE_EXIT
};

class Game {
    SDL_Window* mWindow = nullptr;
    SDL_Renderer* mRenderer = nullptr;
    int mTurnNumber = 0;
    State mGameState = STATE_MENU;
    Side mSide = RED;
    SDL_Event mEvent;

    void handleEvents();
public:
    Game();

    virtual ~Game();

    void loop();
};


#endif //ARKEKNOID_CPP_GAME_H
