#pragma once
#ifndef ROOK_H
#define ROOK_H

#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Piece.h"

class Rook : public Piece {
private:
    sf::Sprite sprite;
    Position position;

public:
    Rook(bool isWhite, Position position, sf::Texture& texture);
    void draw(sf::RenderWindow& window) override;
    std::vector<Position> getPossibleMoves(const Board& board) const override;
    void updateGraphics(float x, float y);
};

#endif // ROOK_H
