#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

#include<vector>
#include <memory>
#include <iostream>

Board::Board() {

    // Loading Textures
    whitePawn.loadFromFile("../imgs/pawnW.png");
    blackPawn.loadFromFile("../imgs/pawnB.png");
    whiteRook.loadFromFile("../imgs/rookW.png");
    blackRook.loadFromFile("../imgs/rookB.png");
    whiteKnight.loadFromFile("../imgs/knightW.png");
    blackKnight.loadFromFile("../imgs/knightB.png");
    whiteBishop.loadFromFile("../imgs/bishopW.png");
    blackBishop.loadFromFile("../imgs/bishopB.png");
    whiteQueen.loadFromFile("../imgs/queenW.png");
    blackQueen.loadFromFile("../imgs/queenB.png");
    whiteKing.loadFromFile("../imgs/kingW.png");
    blackKing.loadFromFile("../imgs/kingB.png");

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            board[x][y] = nullptr;
        }
    }
    initialize();
}

void Board::initialize() {
    setupPieces();
}

void Board::setupPieces() {
    //White 
    for (int i = 0; i < 8; i++) {
        board[i][1] = new Pawn(true, Position{ i, 1 }, whitePawn);
        //std::cout << board[i][1];
    }

    board[0][0] = new Rook(true, Position{ 0, 0 }, whiteRook);
    board[7][0] = new Rook(true, Position{ 7, 0 }, whiteRook);
    board[1][0] = new Knight(true, Position{ 1, 0 }, whiteKnight);
    board[6][0] = new Knight(true, Position{ 6, 0 }, whiteKnight);
    board[2][0] = new Bishop(true, Position{ 2, 0 }, whiteBishop);
    board[5][0] = new Bishop(true, Position{ 5, 0 }, whiteBishop);
    board[3][0] = new Queen(true, Position{ 3, 0 }, whiteQueen);
    board[4][0] = new King(true, Position{ 4, 0 }, whiteKing);

    //std::cout << *board[0][1];

    //Black 
    for (int i = 0; i < 8; i++) {
        board[i][6] = new Pawn(false, Position{ i, 6 }, blackPawn);
    }

    board[0][7] = new Rook(false, Position{ 0, 7 }, blackRook);
    board[7][7] = new Rook(false, Position{ 7, 7 }, blackRook);
    board[1][7] = new Knight(false, Position{ 1, 7 }, blackKnight);
    board[6][7] = new Knight(false, Position{ 6, 7 }, blackKnight);
    board[2][7] = new Bishop(false, Position{ 2, 7 }, blackBishop);
    board[5][7] = new Bishop(false, Position{ 5, 7 }, blackBishop);
    board[4][7] = new Queen(false, Position{ 4, 7 }, blackQueen);
    board[3][7] = new King(false, Position{ 3, 7 }, blackKing);
}

void Board::draw(sf::RenderWindow& window) { // Draw pieces
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (board[y][x]) {
                board[y][x]->draw(window);
            }
        }
    }
}

bool Board::isPositionValid(const Position& position) const {
    return position.getX() >= 0 && position.getX() < 8 &&
        position.getY() >= 0 && position.getY() < 8;
}

bool Board::isPositionOccupied(const Position& position) const {
    int x = position.getX();
    int y = position.getY();

    if (!isPositionValid(position)) { // Range of 8x8 matrix
        return false;
    }

    return board[x][y] != nullptr;
}

Piece* Board::getPieceAt(const Position& position) const {
    if (!isPositionValid(position)) {
        return nullptr;
    }
    //std::cout << position.getX()<<" "<<position.getY();
    return board[position.getX()][position.getY()];
}

void Board::movePiece(const Position& from, const Position& to) {
    if (!isPositionValid(from) || !isPositionValid(to)) {
        return; 
    }

    // Taking piece to new position
    Piece* piece = board[from.getX()][from.getY()];
    board[to.getX()][to.getY()] = piece;
    board[from.getX()][from.getY()] = nullptr;

    if (piece) { // Update
        piece->setPosition(to); 
        piece->updateGraphics(to.getX() * 100, to.getY() * 100);
    }
}

bool Board::isEnemyPieceAt(const Position& position, bool isWhite) const {
    if (!isPositionValid(position)) {
        return false;
    }

    const Piece* piece = getPieceAt(position);
    if (piece && piece->isWhite() != isWhite) {
        return true; // There is enemy
    }

    return false;
}

bool Board::areBothKingsPresent() {
    bool whiteKingFound = false;
    bool blackKingFound = false;

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            Piece* piece = getPieceAt(Position(x, y));
            if (piece && piece->getType() == PieceType::King) {
                if (piece->isWhite()) {
                    blackKingFound = true;
                }
                else {
                    whiteKingFound = true;
                }
            }
        }
    }

    return whiteKingFound && blackKingFound;
}
