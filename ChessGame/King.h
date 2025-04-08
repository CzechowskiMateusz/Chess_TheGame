#pragma once
#ifndef KING_H
#define KING_H

#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Piece.h"

class King : public Piece {
private:
    sf::Sprite sprite;
    Position position;

public:
    King(bool isWhite, Position position, sf::Texture& texture);
    void draw(sf::RenderWindow& window) override;
    std::vector<Position> getPossibleMoves(const Board& board) const override;
    void updateGraphics(float x, float y);
};

#endif // KING_H
