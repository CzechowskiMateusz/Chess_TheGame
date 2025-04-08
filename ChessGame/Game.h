#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Board.h"

class Game {
private:
    Board board;
    bool player; // 0 - Black, 1 - White
    Piece* selectedPiece = nullptr;
    std::vector<Position> possibleMoves; //Current Piece
    bool isGameOver = false; 

public:
    Game();
    void initialize();
    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
    void chessBoard(sf::RenderWindow& window);
    Position convertMousePosToBoardPos(const sf::Vector2i& mousePos);
};

#endif // GAME_H
