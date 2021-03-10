#pragma once

#include <SDL2/SDL.h>

#include <vector>

#include "Rectangle.hpp"

class RenderWindow {
   public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::vector<Rectangle> rects;
    bool sorted;

    RenderWindow(const char *title, const int WIDTH, const int HEIGHT, int n);
    SDL_Texture *loadTexture(const char *path);

    void clear();
    bool handleEvents(SDL_Event &e);
    void sortingAlgorithm();
    void display();
    void cleanUp();
};