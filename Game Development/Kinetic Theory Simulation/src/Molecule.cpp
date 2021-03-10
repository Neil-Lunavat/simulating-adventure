#include "Molecule.hpp"

#include <cmath>
#include <iostream>

void Molecule::update() {
    pos.add(vel);
}

void Molecule::checkForWalls() {
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }

    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }

    if (pos.x + size > 640) {
        pos.x = 640 - size;
        vel.x *= -1;
    }

    if (pos.y + size > 480) {
        pos.y = 480 - size;
        vel.y *= -1;
    }
}

bool Molecule::isCollidingWith(Molecule other) {
    if (sqrt(((pos.x + size / 2) - (other.pos.x + other.size / 2)) * ((pos.x + size / 2) - (other.pos.x + other.size / 2)) + ((pos.y + size / 2) - (other.pos.y + other.size / 2)) * ((pos.y + size / 2) - (other.pos.y + other.size / 2))) < (size / 2) + (other.size / 2)) {
        return true;
    }

    return false;
}
