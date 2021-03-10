#include "RenderWindow.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <random>

#include "Rectangle.hpp"
using namespace std;

RenderWindow::RenderWindow(const char *title, const int WIDTH, const int HEIGHT, int n) {
    random_device rd;   //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd());  //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> dis(0.0, 1.0);

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    int w = WIDTH / n;
    cout << "Width of each: " << w << endl;
    for (int i = 0; i < n; i++) {
        int y = dis(gen) * HEIGHT;
        rects.push_back(Rectangle(w * i, y, w, HEIGHT - y));
    }

    sorted = false;
}

SDL_Texture *RenderWindow::loadTexture(const char *path) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, path);
    return texture;
}

void RenderWindow::clear() {
    SDL_SetRenderDrawColor(renderer, 127, 127, 127, 250);
    SDL_RenderClear(renderer);
}

bool RenderWindow::handleEvents(SDL_Event &e) {
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) return true;
        if (e.type == SDL_WINDOWEVENT_CLOSE) return true;
    }

    return false;
}

void RenderWindow::sortingAlgorithm() {
    if (!sorted)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 250);
    else
        SDL_SetRenderDrawColor(renderer, 100, 255, 123, 255);

    for (Rectangle r : rects) {
        SDL_Rect rect = {r.x, r.y, r.w, r.h};
        SDL_RenderFillRect(renderer, &rect);
    }

    bool swapped = true;
    int i;
    for (i = 0; (i < (int)rects.size() - 1) && swapped; i++) {
        if (rects.at(i) < rects.at(i + 1)) {
            int tempX = rects.at(i + 1).x;
            rects.at(i + 1).x = rects.at(i).x;
            rects.at(i).x = tempX;
            iter_swap(rects.begin() + (i + 1), rects.begin() + (i));

            swapped = false;
            SDL_SetRenderDrawColor(renderer, 123, 255, 140, 255);
        }
    }

    SDL_Rect rect = {rects.at(i).x, rects.at(i).y, rects.at(i).w, rects.at(i).h};
    SDL_RenderFillRect(renderer, &rect);

    if (swapped) sorted = true;
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}

void RenderWindow::cleanUp() {
    SDL_DestroyWindow(window);
    window = NULL;
}