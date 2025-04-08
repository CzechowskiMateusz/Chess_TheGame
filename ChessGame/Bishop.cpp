#include "Bishop.h"
#include "Board.h" 
#include "Position.h" 


Bishop::Bishop(bool isWhite, Position position, sf::Texture& texture) : Piece(PieceType::Bishop, isWhite, position) {

    this->sprite.setTexture(texture);
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = 100.0f / textureSize.x;
    float scaleY = 100.0f / textureSize.y;
    this->sprite.setScale(scaleX, scaleY);
    this->sprite.setPosition(static_cast<float>(position.getX() * 100), static_cast<float>(position.getY() * 100));

}

void Bishop::draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}

std::vector<Position> Bishop::getPossibleMoves(const Board& board) const {
    Position currentPos = getPosition();
    std::vector<Position> moves;

    // Diagonal moves
    int rowOffsets[] = { 1, 1, -1, -1 };
    int colOffsets[] = { 1, -1, 1, -1 };

    for (int i = 0; i < 4; ++i) {
        int newRow = currentPos.getY();
        int newCol = currentPos.getX();
        while (true) {
            newRow += rowOffsets[i];
            newCol += colOffsets[i];
            Position move = { newCol, newRow };

            if (!board.isPositionValid(move)) {
                break; // Out of ranger
            }

            if (!board.isPositionOccupied(move)) {
                moves.push_back(move);
            } else {
                if (board.isEnemyPieceAt(move, isWhite())) {
                    moves.push_back(move);
                }
                break; //Blocked
            }
        }
    }

    return moves;
}

void Bishop::updateGraphics(float x, float y) {
    sprite.setPosition(x, y);
}

