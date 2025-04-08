#include "Pawn.h"
#include "Board.h" 
#include "Position.h" 
#include <iostream>

Pawn::Pawn(bool isWhite, Position position, sf::Texture& texture): Piece(PieceType::Pawn, isWhite, position) {
    //std::cout << "Inicjalizacja pionka na pozycji [" << position.getX() << ", " << position.getY() << "]\n";
    
    this->sprite.setTexture(texture); 
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = 100.0f / textureSize.x;
    float scaleY = 100.0f / textureSize.y;
    this->sprite.setScale(scaleX, scaleY);
  
    this->sprite.setPosition(static_cast<float>(position.getX()*100), static_cast<float>(position.getY()*100));

}

void Pawn::draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}

std::vector<Position> Pawn::getPossibleMoves(const Board& board) const {
    Position currentPos = getPosition();
    std::cout << currentPos.getY() << " " << currentPos.getX();
    std::vector<Position> moves;

    // One forward
    int forwardRow = currentPos.getY() + (isWhite() ? 1 : -1);
    Position forward = { currentPos.getX(), forwardRow };
    if (board.isPositionValid(forward) && !board.isPositionOccupied(forward)) {
        moves.push_back(forward);
    }

    // First move
    if ((isWhite() && currentPos.getY() == 1) || (!isWhite() && currentPos.getY() == 6)) {
        int twoForwardRow = currentPos.getY() + (isWhite() ? 2 : -2);
        Position twoForward = { currentPos.getX(), twoForwardRow };
        if (board.isPositionValid(twoForward) && !board.isPositionOccupied(twoForward)) {
            moves.push_back(twoForward);
        }
    }

    // Diagonal 
    for (int i = -1; i <= 1; i += 2) {
        int diagonalRow = currentPos.getY() + (isWhite() ? 1 : -1);
        int diagonalCol = currentPos.getX() + i;
        Position diagonal = { diagonalCol, diagonalRow };
        if (board.isPositionValid(diagonal) && board.isEnemyPieceAt(diagonal, isWhite())) {
            moves.push_back(diagonal);
        }
    }

    // Debugging
    /*
    std::cout << "Mo¿liwe ruchy dla pionka na pozycji [" << currentPos.getX() << ", " << currentPos.getY() << "]:\n";
    for (const auto& move : moves) {
        std::cout << "  [" << move.getX() << ", " << move.getY() << "]\n";
    } 
    */

    return moves;
}

void Pawn::updateGraphics(float x, float y) {
    sprite.setPosition(x, y);
}