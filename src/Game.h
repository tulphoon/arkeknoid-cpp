//
// Created by Dawid Osuchowski on 21/12/2019.
//

#ifndef ARKEKNOID_CPP_GAME_H
#define ARKEKNOID_CPP_GAME_H


#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <unordered_map>
#include "GameObject.h"

enum State {
    STATE_PLAYING,
    STATE_EXIT
};

/**
 * @class Game
 */

class Game {
    SDL_Window* mWindow = nullptr;
    int mWindowWidth, mWindowHeight;
    SDL_Renderer* mRenderer = nullptr;
    State mGameState = STATE_PLAYING;

    SDL_Event mEvent;

    /// Handle input from user
    void handleEvents();

    /// Update the game world
    void update(const double &elapsed);

    /// Render the game objects on the screen
    void render();

public:
    /// Create a Game with a given window title, width and height
    Game(const std::string& windowTitle, const int& windowWidth, const int& windowHeight);

    ~Game();

    std::unordered_map<SDL_Scancode, bool> keyPressed;
    std::vector<GameObject*> mGameObjects;

    /// Start the game loop
    void run();

    SDL_Renderer *getRenderer() const;

    int getWindowWidth() const;

    int getWindowHeight() const;

    /// Check for collision between objects
    void physics();

    void setGameState(State mGameState);
};


#endif //ARKEKNOID_CPP_GAME_H
