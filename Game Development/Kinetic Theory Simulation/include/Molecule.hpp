#pragma once
#include <vector>

#include "Math.hpp"
class Molecule {
   public:
    PVector pos, vel;
    float size;

    Molecule() {
        pos = PVector();
        vel = PVector();
    }

    Molecule(float x, float y) {
        pos = PVector(x, y);
        vel = PVector();
    }

    Molecule(float x, float y, float size_) {
        pos = PVector(x, y);
        vel = PVector();
        size = size_;
    }

    Molecule(float x, float y, float x_vel, float y_vel) {
        pos = PVector(x, y);
        vel = PVector(x_vel, y_vel);
    }

    Molecule(float x, float y, float x_vel, float y_vel, float size_) {
        pos = PVector(x, y);
        vel = PVector(x_vel, y_vel);
        size = size_;
    }

    void update();
    void checkForWalls();
    bool isCollidingWith(Molecule other);
};