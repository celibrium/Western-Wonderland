#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Wheel.h"
#include "Graduation.h"
#include "Player.h"
#include "GameBoard.h"
#include "Events.h"
#include "game.h"
#include "majorSelection.h"
#include "ResourceDisplay.h"

/**
 * @file main.cpp
 * @brief Entry point for the Western Wonderland game.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

// Constants
const int TILE_SIZE = 40;                  /**< Size of each tile in pixels. */
const int BOARD_SIZE = 11;                 /**< Size of the game board (number of tiles in each dimension). */
const int WINDOW_WIDTH = TILE_SIZE * BOARD_SIZE; /**< Width of the game window. */
const int WINDOW_HEIGHT = TILE_SIZE * BOARD_SIZE; /**< Height of the game window. */

/**
 * @brief Main function to run the Western Wonderland game.
 * @return Exit status of the program.
 */
int main() {
    int turn = 1; 

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Western Wonderland");

    GameBoard board;
    Wheel wheel;
    float arrowAngle = 0;

    Player player1(board.getIveyPath(), sf::Color::Red);
    Player player2(board.getWesternPath(), sf::Color::Blue);

    // Initialize player attributes
    player1.setHappiness(0);
    player1.setGPA(0);
    player1.setDebt(0);

    player2.setHappiness(0);
    player2.setGPA(0);
    player2.setDebt(0);

    // Display major selection screen
    bool startClicked = gamestart::gamestart(window);
    int majorClicked;
    int majorChosen1 = 0;
    int majorChosen2 = 0;

    if (startClicked) {
        while (window.isOpen()) {
            // Check for graduation event and calculate scores
            if (player1.finished() && player2.finished()) {
                Graduation::graduationEvent(window, "Graduation", player1, player2);
            }

            // Update and draw game elements
            window.clear();
            board.draw(window);
            player1.update();
            player2.update();
            player1.draw(window);
            player2.draw(window);
            wheel.DrawWheel(arrowAngle, window);

            window.display();

            // Handle events
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // Major selection for Player 1
                if (player1.getPosition() == (sf::Vector2f(220, 420)) && majorChosen1 == 0) {
                    majorClicked = majorSelection::majorEvent(window, "Player 1 Choose Your Path");
                    if (majorClicked == 0) {
                        player1.setPath(board.getWesternPath());
                        majorChosen1 = 1;
                    } else if (majorClicked == 1 && majorChosen1 == 0) {
                        player1.setPath(board.getIveyPath());
                        majorChosen1 = 1;
                    }
                }

                // Major selection for Player 2
                if (player2.getPosition() == (sf::Vector2f(220, 420)) && majorChosen2 == 0) {
                    majorClicked = majorSelection::majorEvent(window, "Player 2 Choose Your Path");
                    if (majorClicked == 0) {
                        player2.setPath(board.getWesternPath());
                        majorChosen2 = 1;
                    } else if (majorClicked == 1 && majorChosen2 == 0) {
                        player2.setPath(board.getIveyPath());
                        majorChosen2 = 1;
                    }
                }

                // Display resources for Player 1
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
                    ResourceDisplay::resourceDisplay(window, player1, "Resources");
                }

                // Display resources for Player 2
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
                    ResourceDisplay::resourceDisplay(window, player2, "Resources");
                }

                // Spin the wheel on Space key release
                if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
                    std::pair<int, float> result = wheel.SpinWheel(window);
                    int spinResult = result.first;
                    arrowAngle = result.second;

                    if (turn == 1 && !player1.finished()) {
                        player1.move(spinResult);
                        if (!player2.finished()) {
                            turn = 2;
                        }
                    } else if (turn == 2 && !player2.finished()) {
                        player2.move(spinResult);
                        if (!player1.finished()) {
                            turn = 1;
                        }
                    }
                }

                // Event trigger for Player 1
                if (player1.onEvent(board.getEventSpaces()) && player1.justMoved() == true) {
                    events::playerEvent(window, "event", player1);
                }

                // Event trigger for Player 2
                if (player2.onEvent(board.getEventSpaces()) && player2.justMoved() == true) {
                    events::playerEvent(window, "event", player2);
                }
            }
        }

        // Display final game state
        window.clear();
        board.draw(window);
        wheel.DrawWheel(arrowAngle, window);
        player1.update();
        player2.update();
        player1.draw(window);
        player2.draw(window);
        window.display();
    }
    return 0;
}
