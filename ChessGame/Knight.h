#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H

#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Piece.h"

class Knight : public Piece {
private:
    sf::Sprite sprite;
    Position position;

public:
    Knight(bool isWhite, Position position, sf::Texture& texture);
    void draw(sf::RenderWindow& window) override;
    std::vector<Position> getPossibleMoves(const Board& board) const override;
    void updateGraphics(float x, float y);
};

#endif // KNIGHT_H
