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


/**
 * Contains states of the Game
 */
enum State {
    STATE_PLAYING,
    STATE_GAMEOVER,
    STATE_EXIT
};

/**
 * @class Game
 * @brief Represents the game
 */

class Game {
    SDL_Window* mWindow = nullptr;
    int mWindowWidth, mWindowHeight;
    SDL_Renderer* mRenderer = nullptr;
    State mGameState = STATE_PLAYING;
    double mScore = 0;

    double mCurrentBestScore;
    TTF_Font *font; /// Global font used in text rendering

    SDL_Event mEvent;

    /// Handle input from user
    void handleEvents();

    /**
     * Call update for all game objects
     * @param elapsed time elapsed since the last frame
     */
    void update(const double &elapsed);

    /// Render the game objects on the screen
    void render();

public:
    /**
     * Create the Game object
     * @param windowTitle
     * @param windowWidth
     * @param windowHeight
     */
    Game(const std::string& windowTitle, const int& windowWidth, const int& windowHeight);

    /**
     * Destroys objects
     */
    ~Game();

    std::unordered_map<SDL_Scancode, bool> keyPressed; /// Contains list of keyboard keys and information about their state
    std::vector<GameObject*> mGameObjects; /// Contains all objects from the Game
    unsigned int ballLastIncreaseSpeedTime, ballCurrentIncreaseSpeedTime; /// Timer for speeding up the ball

    /// Start the game loop
    void run();

    SDL_Renderer *getRenderer() const;

    int getWindowWidth() const;

    int getWindowHeight() const;

    /// Check for collision between objects
    void physics();

    void setGameState(State mGameState);

    /**
     * Read best score from a text file
     * @return The information about whether the score was read successfully
     */
    bool readScoreFromFile();

    /**
     * Save best score to a text file
     * @return The information about whether the score was saved successfully
     */
    bool saveScoreToFile();

    double getScore() const;
};


#endif //ARKEKNOID_CPP_GAME_H
