#pragma once

class Rectangle {
   public:
    int x, y, w, h, index;

    Rectangle(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_) {}

    bool operator<(Rectangle &other) {
        return y < other.y;
    }

    bool operator>(Rectangle &other) {
        return h > other.h;
    }
};