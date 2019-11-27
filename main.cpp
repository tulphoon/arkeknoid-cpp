#include <iostream>
#include <SDL.h>

int main() {
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // create a window
    SDL_Window *window = nullptr;
    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    if(window == nullptr) {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // create a renderer
    SDL_Renderer *renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(renderer == nullptr) {
        SDL_Log("Could not create renderer: %s\n", SDL_GetError());
    }



    // wait 3000 milliseconds (3s)
    SDL_Delay(3000);

    // destroy window
    SDL_DestroyWindow(window);

    // deactivate subsystems and quit SDL
    SDL_Quit();

    return 0;
}