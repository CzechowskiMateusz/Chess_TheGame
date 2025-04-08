#include "Piece.h"

Piece::Piece(PieceType type, bool isWhite, Position position)
    : type(type), white(isWhite), position(position) {}

PieceType Piece::getType() const {
    return type;
}

bool Piece::isWhite() const {
    return white;
}

Position Piece::getPosition() const {
    return position;
}

void Piece::setPosition(const Position& newPosition) {
    position = newPosition;
}
