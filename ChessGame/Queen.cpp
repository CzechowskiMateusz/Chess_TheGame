#include "Queen.h"
#include "Board.h" 

Queen::Queen(bool isWhite, Position position, sf::Texture& texture) : Piece(PieceType::Queen, isWhite, position) {

    this->sprite.setTexture(texture);
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = 100.0f / textureSize.x;
    float scaleY = 100.0f / textureSize.y;
    this->sprite.setScale(scaleX, scaleY);
    this->sprite.setPosition(static_cast<float>(position.getX() * 100), static_cast<float>(position.getY() * 100));

}

void Queen::draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}

std::vector<Position> Queen::getPossibleMoves(const Board& board) const {
    Position currentPos = getPosition();
    std::vector<Position> moves;

    // Up
    for (int col = currentPos.getX() + 1; col < 8; ++col) {
        Position rightMove = { col, currentPos.getY() };
        if (board.isPositionValid(rightMove)) {
            if (!board.isPositionOccupied(rightMove)) {
                moves.push_back(rightMove);
            } else {
                if (board.isEnemyPieceAt(rightMove, isWhite())) {
                    moves.push_back(rightMove);
                }
                break; // Blocked
            }
        } else {
            break; // Out of indexc
        }
    }

    // Down
    for (int col = currentPos.getX() - 1; col >= 0; --col) {
        Position leftMove = { col, currentPos.getY() };
        if (board.isPositionValid(leftMove)) {
            if (!board.isPositionOccupied(leftMove)) {
                moves.push_back(leftMove);
            } else {
                if (board.isEnemyPieceAt(leftMove, isWhite())) {
                    moves.push_back(leftMove);
                }
                break; // Blocked
            }
        } else {
            break; // Out of index
        }
    }

    // Right
    for (int row = currentPos.getY() + 1; row < 8; ++row) {
        Position upMove = { currentPos.getX(), row };
        if (board.isPositionValid(upMove)) {
            if (!board.isPositionOccupied(upMove)) {
                moves.push_back(upMove);
            }else {
                if (board.isEnemyPieceAt(upMove, isWhite())) {
                    moves.push_back(upMove);
                }
                break; // PBlockekd
            }
        }else {
            break; //Out of board
        }
    }

    //Left
    for (int row = currentPos.getY() - 1; row >= 0; --row) {
        Position downMove = { currentPos.getX(), row };
        if (board.isPositionValid(downMove)) {
            if (!board.isPositionOccupied(downMove)) {
                moves.push_back(downMove);
            } else {
                if (board.isEnemyPieceAt(downMove, isWhite())) {
                    moves.push_back(downMove);
                }
                break; // Blocked
            }
        } else {
            break; // POut of board
        }
    }

    // Diagonal
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
                break; // Out
            }

            if (!board.isPositionOccupied(move)) {
                moves.push_back(move);
            } else {
                if (board.isEnemyPieceAt(move, isWhite())) {
                    moves.push_back(move);
                }
                break; // Blocked
            }
        }
    }

    return moves;
}

void Queen::updateGraphics(float x, float y) {
    sprite.setPosition(x, y);
}