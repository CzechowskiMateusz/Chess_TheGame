#include "Game.h"
#include "King.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(){
    board.initialize();
    player = 1; //White alwways starts first
}

void Game::initialize() {
    board.setupPieces();
}

void Game::draw(sf::RenderWindow& window) {
    if (isGameOver) { // When games end
        window.clear();
        sf::Text gameOverText;
        sf::Font font;
        font.loadFromFile("../font/arial.ttf");
        gameOverText.setFont(font);
        gameOverText.setCharacterSize(40); 
        gameOverText.setFillColor(sf::Color::White); 
        if (player) {
            gameOverText.setString("Game Over. Black won!");
        } else {
            gameOverText.setString("Game Over. White won!");
        }
        gameOverText.setPosition(200, 400);
        window.draw(gameOverText); // Final text, Esc.
    } else {

        board.draw(window); // Board and pieces
        if (selectedPiece) {
            for (const auto& move : possibleMoves) { //Possible moves for a piece
                sf::CircleShape dot(5.f);
                dot.setFillColor(sf::Color::Red);
                dot.setPosition(move.getX() * 100 + 50, move.getY() * 100 + 50);
                window.draw(dot);
            }
        }
    }

}

void Game::update(sf::RenderWindow& window) {
    if (isGameOver) {
        return; // No more moves
    }

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    Position clickedPosition = convertMousePosToBoardPos(mousePos);
    //std::cout << "Pozycja myszy: X=" << mousePos.x << ", Y=" << mousePos.y << std::endl;

        if (!selectedPiece) { // Clicked piece
            selectedPiece = board.getPieceAt(clickedPosition);
            if (selectedPiece && selectedPiece->isWhite() == player) {
                possibleMoves = selectedPiece->getPossibleMoves(board);
            }
            else {
                selectedPiece = nullptr;
            }
        }
        else {
            if (std::find(possibleMoves.begin(), possibleMoves.end(), clickedPosition) != possibleMoves.end()) { // Make a move
                board.movePiece(selectedPiece->getPosition(), clickedPosition);
                if (!board.areBothKingsPresent()) {
                    isGameOver = true;
                    //std::cout << "Game Over. Player " << (!player ? "Black" : "White") << " has won by capturing the King!" << std::endl;  
                }

                player = !player; // Zmiana gracza
                selectedPiece = nullptr;
                possibleMoves.clear();

            }
            else {
                selectedPiece = nullptr;
            }
        }
}

void Game::chessBoard(sf::RenderWindow& window){

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {  // Board look
            sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f)); 
            rectangle.setPosition(x * 100.f, y * 100.f);

            if ((x + y) % 2 == 0) {
                rectangle.setFillColor(sf::Color::White);
            }
            else {
                rectangle.setFillColor(sf::Color::Black);
            }
            window.draw(rectangle); 
        }
    }
}

Position Game::convertMousePosToBoardPos(const sf::Vector2i& mousePos) {
    Position pos(mousePos.x / 100, mousePos.y / 100);
   // std::cout << "Kliknieto na pozycji: " << pos.getX() << ", " << pos.getY() << std::endl;
    return pos;
}

