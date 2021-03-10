#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <random>
#include <vector>

#include "Molecule.hpp"
#include "RenderWindow.hpp"

int main(int argc, char *argv[]) {
    std::random_device rd;   //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());  //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);

    const int WIDTH = 640, HEIGHT = 480;

    if (SDL_Init(SDL_INIT_VIDEO) > 0) std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
    if (!IMG_Init(IMG_INIT_PNG)) std::cout << "Image Initialization failed: " << SDL_GetError() << std::endl;

    RenderWindow window("KTheory Simulation", WIDTH, HEIGHT);

    SDL_Texture *circle = window.loadTexture("images/Purple Circle.png");

    std::vector<Molecule> molecules;

    for (int i = 0; i < 10; i++) {
        molecules.push_back(Molecule(dis(gen) * WIDTH, dis(gen) * HEIGHT, (dis(gen) * 4) - 1, (dis(gen) * 4) - 1, 50));
    }

    bool done = false;
    SDL_Event e;
    while (!done) {
        window.clear();
        done = window.handleEvents(e);

        window.handleMolecules(molecules, circle);

        window.display();
    }

    SDL_Quit();

    return 0;
}