#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "RenderWindow.hpp"

int main(int argc, char *argv[]) {
    const int WIDTH = 640, HEIGHT = 480;

    if (SDL_Init(SDL_INIT_VIDEO) > 0) std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
    if (!IMG_Init(IMG_INIT_PNG)) std::cout << "Image Initialization failed: " << SDL_GetError() << std::endl;

    RenderWindow window("BUBBLE SORT VISUALIZER", WIDTH, HEIGHT, 80);

    bool done = false;
    SDL_Event e;
    while (!done) {
        window.clear();
        done = window.handleEvents(e);

        window.sortingAlgorithm();

        window.display();

        SDL_Delay(10);
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}