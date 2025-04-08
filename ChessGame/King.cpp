#include "King.h"
#include "Board.h" 
#include "Position.h" 


King::King(bool isWhite, Position position, sf::Texture& texture) : Piece(PieceType::King, isWhite, position) {

    this->sprite.setTexture(texture);
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = 100.0f / textureSize.x;
    float scaleY = 100.0f / textureSize.y;
    this->sprite.setScale(scaleX, scaleY);
    this->sprite.setPosition(static_cast<float>(position.getX() * 100), static_cast<float>(position.getY() * 100));

}

void King::draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}

std::vector<Position> King::getPossibleMoves(const Board& board) const {
    Position currentPos = getPosition();
    std::vector<Position> moves;

    // All moves
    int rowOffsets[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int colOffsets[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; ++i) {
        int newRow = currentPos.getY() + rowOffsets[i];
        int newCol = currentPos.getX() + colOffsets[i];
        Position move = { newCol, newRow };

        if (board.isPositionValid(move)) {
            if (!board.isPositionOccupied(move) || board.isEnemyPieceAt(move, isWhite())) {
                moves.push_back(move);
            }
        }
    }

    return moves;
}

void King::updateGraphics(float x, float y) {
    sprite.setPosition(x, y);
}