#pragma once

#include <SDL2/SDL.h>

#include <vector>

#include "Molecule.hpp"

class RenderWindow {
   public:
    SDL_Window *window;
    SDL_Renderer *renderer;

    RenderWindow(const char *title, const int width, const int height);
    SDL_Texture *loadTexture(const char *path);

    void clear();
    bool handleEvents(SDL_Event &e);
    void handleMolecules(std::vector<Molecule> &molecules, SDL_Texture *circle);
    void display();
};