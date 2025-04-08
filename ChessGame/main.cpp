#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    //Entry game loading
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chessy!");

   Game chessGame;  // New Game
   chessGame.initialize(); 
   chessGame.chessBoard(window);

    while (window.isOpen()){ // Game loop
        sf::Event event;

        //Event polling
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed: // Closing Window
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) { // Controlling Events and Ending 
                chessGame.update(window);
            }
        }

        // Render and genarate new moves 
        window.clear();
        chessGame.chessBoard(window);
        chessGame.draw(window);
        window.display();
    }

    return 0;
}
