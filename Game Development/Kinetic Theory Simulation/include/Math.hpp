#pragma once

#include <cmath>

class PVector {
   public:
    float x, y;

    PVector() : x(0), y(0) {}
    PVector(float x_, float y_) : x(x_), y(y_) {}

    void add(PVector other) {
        x += other.x;
        y += other.y;
    }

    void sub(PVector other) {
        x -= other.x;
        y -= other.y;
    }

    void mult(PVector other) {
        x *= other.x;
        y *= other.y;
    }

    void div(PVector other) {
        x /= other.x;
        y /= other.y;
    }

    float mag() {
        return sqrt((x * x) + (y * y));
    }
};