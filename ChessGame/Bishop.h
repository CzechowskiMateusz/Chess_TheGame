#pragma once
#pragma once
#ifndef BISHOP_H
#define BISHOP_H

#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Piece.h"

class Bishop : public Piece {
private:
    sf::Sprite sprite;
    Position position;

public:
    Bishop(bool isWhite, Position position, sf::Texture& texture);
    void draw(sf::RenderWindow& window) override;
    std::vector<Position> getPossibleMoves(const Board& board) const override;
    void updateGraphics(float x, float y);
};

#endif // BISHOP_H
