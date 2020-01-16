//
// Created by Dawid Osuchowski on 21/12/2019.
//

#include "Game.h"
#include "Player.h"
#include "Ball.h"

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
    if(!readScoreFromFile()) {
        mCurrentBestScore = 0;
    }

    font = TTF_OpenFont("assets/fonts/Lato-Regular.ttf", 22);
    if(!font) {
        SDL_Log("TTF_OpenFont: %s\n", TTF_GetError());
        return;
    }

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
    ball.setVel({100, -400});
    ball.setColor({255, 255, 255, 255});

    // Add ball and player to game objects vector
    mGameObjects.push_back(&ball);
    mGameObjects.push_back(&player);

    unsigned int lastTime = SDL_GetTicks();

    // Run game loop
    while (mGameState != STATE_EXIT) {
        unsigned int current = SDL_GetTicks();
        double elapsed = current - lastTime;
        elapsed = elapsed / 1000;

        handleEvents();
        update(elapsed);
        physics();
        render();

        lastTime = current;
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

    // Create rectangle and color for the scoreText
    SDL_Color color = {255, 255, 255};
    SDL_Rect dstrect {5, 0, 50, 50};

    auto scoreText{("Score: " + std::to_string(static_cast<int>(mScore))).c_str()};

    // Get dimensions needed to display the text nicely
    if(TTF_SizeText(font, scoreText, &dstrect.w, &dstrect.h)) {
        SDL_Log("TTF_SizeText: %s\n", TTF_GetError());
        mGameState = STATE_EXIT;
    }

    // Create texture from surface
    SDL_Surface * surface = TTF_RenderText_Blended(font, scoreText, color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(mRenderer, surface);

    // Render texture on screen
    SDL_RenderCopy(mRenderer, texture, NULL, &dstrect);

    SDL_RenderPresent(mRenderer);

    // Free memory
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
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
