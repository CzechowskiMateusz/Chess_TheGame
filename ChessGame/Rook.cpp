#include "Rook.h"
#include "Board.h" 


Rook::Rook(bool isWhite, Position position, sf::Texture& texture): Piece(PieceType::Rook, isWhite, position) {
    this->sprite.setTexture(texture); 
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = 100.0f / textureSize.x;
    float scaleY = 100.0f / textureSize.y;
    this->sprite.setScale(scaleX, scaleY);
    this->sprite.setPosition(static_cast<float>(position.getX()*100), static_cast<float>(position.getY()*100));
}

void Rook::draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}

std::vector<Position> Rook::getPossibleMoves(const Board& board) const {
    Position currentPos = getPosition();
    std::vector<Position> moves;

    //  Up
    for (int row = currentPos.getY() + 1; row < 8; ++row) {
        Position upMove = { currentPos.getX(), row };
        if (board.isPositionValid(upMove)) {
            if (!board.isPositionOccupied(upMove)) {
                moves.push_back(upMove);
            } else {
                if (board.isEnemyPieceAt(upMove, isWhite())) {
                    moves.push_back(upMove);
                }
                break; // Blocked
            }
        } else {
            break; // Out of index
        }
    }

    // Down
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
            break; // Out of index
        }
    }

    // Right
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
            break; // Out of range
        }
    }

    // Left
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

    return moves;
}

void Rook::updateGraphics(float x, float y) {
    sprite.setPosition(x, y);
}