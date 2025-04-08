#pragma once
#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Position.h" 

class Board; 

enum class PieceType {
    Pawn, Knight, Bishop, Rook, Queen, King
};

class Piece {
protected:
    PieceType type;
    bool white;
    Position position;

public:
    Piece(PieceType type, bool isWhite, Position position);
    virtual ~Piece() = default;
    virtual void draw(sf::RenderWindow& window) = 0;
    PieceType getType() const;
    bool isWhite() const;
    Position getPosition() const;
    void setPosition(const Position& newPosition);
    virtual std::vector<Position> getPossibleMoves(const Board& board) const = 0; // Abstract function
    virtual void updateGraphics(float x,float y) = 0;

};

#endif // PIECE_H
