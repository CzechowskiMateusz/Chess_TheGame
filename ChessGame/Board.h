#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <SFML/Graphics.hpp>
#include "Piece.h" 

class Board {
private:
    std::array<std::array<Piece*, 8>, 8> board;
    sf::Texture whitePawn;
    sf::Texture whiteRook;
    sf::Texture whiteKnight;
    sf::Texture whiteBishop;
    sf::Texture whiteQueen;
    sf::Texture whiteKing;
    sf::Texture blackPawn;
    sf::Texture blackRook;
    sf::Texture blackKnight;
    sf::Texture blackBishop;
    sf::Texture blackQueen;
    sf::Texture blackKing;

public:
    Board();
    void initialize(); 
    void setupPieces();
    void draw(sf::RenderWindow& window);
    bool isPositionValid(const Position& position) const;
    bool isPositionOccupied(const Position& position) const;
    Piece* getPieceAt(const Position& position) const;
    void movePiece(const Position& from, const Position& to);
    bool isEnemyPieceAt(const Position& position, bool isWhite) const;
    bool areBothKingsPresent();
};
#endif // BOARD_H