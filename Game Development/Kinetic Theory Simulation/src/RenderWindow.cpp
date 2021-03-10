#include "RenderWindow.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>

#include "Molecule.hpp"

using namespace std;

RenderWindow::RenderWindow(const char* title, const int width, const int height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::loadTexture(const char* path) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, path);

    if (texture == NULL) cout << "Error loading texture: " << SDL_GetError() << endl;
    return texture;
}

void RenderWindow::clear() {
    SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);
    SDL_RenderClear(renderer);
}

bool RenderWindow::handleEvents(SDL_Event& e) {
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return true;
        }
    }
    return false;
}

void RenderWindow::handleMolecules(vector<Molecule>& molecules, SDL_Texture* circle) {
    for (int i = 0; i < (int)molecules.size(); i++) {
        //
        molecules.at(i).update();
        molecules.at(i).checkForWalls();

        for (int j = 0; j < (int)molecules.size(); j++) {
            if (i != j) {
                if (molecules.at(i).isCollidingWith(molecules.at(j))) {
                    PVector tempVel(molecules.at(i).vel.x, molecules.at(i).vel.y);
                    molecules.at(i).vel = PVector(molecules.at(j).vel.x, molecules.at(j).vel.y);
                    molecules.at(j).vel = tempVel;
                }
            }
        }

        SDL_Rect r = {(int)molecules.at(i).pos.x, (int)molecules.at(i).pos.y, (int)molecules.at(i).size, (int)molecules.at(i).size};
        SDL_RenderCopy(renderer, circle, NULL, &r);
        //
    }
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}