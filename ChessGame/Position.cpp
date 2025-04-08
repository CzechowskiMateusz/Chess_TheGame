#include "Position.h"

Position::Position(int x, int y) : x(x), y(y) {}

int Position::getX() const { return x; }
int Position::getY() const { return y; }

void Position::setX(int x) { this->x = x; }
void Position::setY(int y) { this->y = y; }

bool Position::isValid() const {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool Position::operator==(const Position& other) const {
    return x == other.x && y == other.y;
}
