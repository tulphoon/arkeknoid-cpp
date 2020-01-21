//
// Created by Dawid Osuchowski on 21/12/2019.
//

#include "Game.h"
#include "Player.h"
#include "Ball.h"
#include "Text.h"

#include <SDL.h>
#include <fstream>

Game::Game(const std::string& windowTitle, const int& windowWidth, const int& windowHeight) : mWindowWidth(windowWidth), mWindowHeight(windowHeight) {
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
    }

    // initialize TTF
    if(TTF_Init() != 0) {
        SDL_Log("Unable to initialize SDL_ttf: %s\n", TTF_GetError());
    }

    // create a window
    mWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWindowWidth, mWindowHeight, SDL_WINDOW_SHOWN);

    if(mWindow == nullptr) {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
    }

    // create a renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

    if(mRenderer == nullptr) {
        SDL_Log("Could not create renderer: %s\n", SDL_GetError());
    }
}

Game::~Game() {
    saveScoreToFile();

    // free the global font
    TTF_CloseFont(font);
    font = nullptr;

    // Destroy renderer
    SDL_DestroyRenderer(mRenderer);

    // destroy window
    SDL_DestroyWindow(mWindow);

    // deactivate subsystems and quit SDL
    TTF_Quit();
    SDL_Quit();

}

void Game::run() {
    font = TTF_OpenFont("assets/fonts/Lato-Regular.ttf", 22);
    if(!font) {
        SDL_Log("TTF_OpenFont: %s\n", TTF_GetError());
        return;
    }

    if(!readScoreFromFile()) {
        mCurrentBestScore = 0;
    }

    // Create score text and set attributes
    Text score(this, "Score: " + std::to_string(static_cast<int>(mScore)), font);
    score.setRect({5, 0, 0, 0});
    score.setColor({255, 255, 255});

    // Create bestScore text and set attributes
    Text bestScore(this, "Current Best Score: " + std::to_string(static_cast<int>(mCurrentBestScore)), font);
    bestScore.setRect({mWindowWidth / 2 - 100, mWindowHeight / 2});
    bestScore.setColor({61, 135, 255});

    Text yourScore(this, "Your score: " + std::to_string(static_cast<int>(mScore)), font);
    yourScore.setRect({bestScore.getRect().x, bestScore.getRect().y + 50});
    yourScore.setColor({68, 255, 0});

    Text instruction(this, "Exit the game, by closing the window", font);
    instruction.setRect({mWindowWidth / 2 - 150, mWindowHeight - 100});
    instruction.setColor({116, 61, 255});

    // Create player and set attributes
    Player player(this);
    player.setRect({0, 0, 100, 20});
    player.setPos({300, 550});
    player.setVel({500, 0});
    player.setColor({255, 0, 0, 255});

    // Create ball and set attributes
    Ball ball(this);
    ball.setRect({0, 0, 10, 10});
    ball.setPos({100, 400});
    ball.setVel({1, -1});
    ball.setVel(ball.getVel().normalized() * ball.getSpeed());
    ball.setColor({255, 255, 255, 255});

    // Add ball and player to game objects vector
    mGameObjects.push_back(&ball);
    mGameObjects.push_back(&player);
    mGameObjects.push_back(&score);

    unsigned int lastTime = SDL_GetTicks();
    ballLastIncreaseSpeedTime = SDL_GetTicks();

    // Run game loop
    while (mGameState != STATE_EXIT) {
        switch (mGameState) {
            case STATE_EXIT:
                break;

            case STATE_GAMEOVER:
                handleEvents();

                mGameObjects.clear();
                mGameObjects.push_back(&bestScore);
                mGameObjects.push_back(&yourScore);
                mGameObjects.push_back(&instruction);
                render();
                break;

            case STATE_PLAYING:
                unsigned int current = SDL_GetTicks();
                double elapsed = current - lastTime;
                elapsed = elapsed / 1000;

                ballCurrentIncreaseSpeedTime = SDL_GetTicks();

                handleEvents();
                update(elapsed);
                score.setString("Score: " + std::to_string(static_cast<int>(mScore)));
                bestScore.setString("Current Best Score: " + std::to_string(static_cast<int>(mCurrentBestScore)));
                yourScore.setString("Your score: " + std::to_string(static_cast<int>(mScore)));
                physics();
                render();

                lastTime = current;
                break;
        }
    }
}

void Game::handleEvents() {
    while(SDL_PollEvent(&mEvent)) {
        switch (mEvent.type) {
            case SDL_QUIT:
                mGameState = STATE_EXIT;
                break;

            case SDL_KEYDOWN:
                keyPressed[mEvent.key.keysym.scancode] = true;
                break;

            case SDL_KEYUP:
                keyPressed[mEvent.key.keysym.scancode] = false;
                break;
        }
    }
}

SDL_Renderer *Game::getRenderer() const {
    return mRenderer;
}

void Game::update(const double &elapsed) {
        // Update score
        mScore += elapsed;

        // Update best score
        if(mScore > mCurrentBestScore) {
            mCurrentBestScore = mScore;
        }

        // Run each object's update method
        for(auto gameObject : mGameObjects) {
            gameObject->update(elapsed);
        }

}

void Game::render() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);

    for(auto gameObject : mGameObjects) {
        gameObject->render(mRenderer);
    }

    SDL_RenderPresent(mRenderer);
}

int Game::getWindowWidth() const {
    return mWindowWidth;
}

int Game::getWindowHeight() const {
    return mWindowHeight;
}

void Game::physics() {
    // Check for collisions between objects
    for (int i = 0; i < mGameObjects.size(); ++i) {
        auto &A = mGameObjects[i];
        for (int j = i+1; j < mGameObjects.size(); ++j) {
            auto &B = mGameObjects[j];
            if(A->isColliding(B)) {
                A->handleCollision(B);
                B->handleCollision(A);
            }
        }
    }
}

void Game::setGameState(State mGameState) {
    Game::mGameState = mGameState;
}

bool Game::saveScoreToFile() {
    std::ofstream scoreFile("scoreBest.txt");
    if(scoreFile.is_open()) {
        scoreFile << std::to_string(mCurrentBestScore);

        scoreFile.close();

        return true;
    } else std::cout << "Unable to open scoreBest.txt file" << std::endl;

    return false;
}

bool Game::readScoreFromFile() {
    std::string line;

    std::ifstream scoreFile("scoreBest.txt");
    if(scoreFile.is_open()) {
        getline(scoreFile, line);

        mCurrentBestScore = std::stod(line);

        scoreFile.close();

        return true;
    } else std::cout << "Unable to open scoreBest.txt file" << std::endl;

    return false;
}

double Game::getScore() const {
    return mScore;
}
