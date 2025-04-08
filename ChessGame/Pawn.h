#pragma once
#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Piece.h"

class Pawn : public Piece {
private:
    sf::Sprite sprite;
    Position position;

public:
    Pawn(bool isWhite, Position position, sf::Texture& texture);
    void draw(sf::RenderWindow& window) override;
    std::vector<Position> getPossibleMoves(const Board& board) const override;
    void updateGraphics(float x, float y);
};

#endif // PAWN_H
