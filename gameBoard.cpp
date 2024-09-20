#include <SFML/Graphics.hpp>
#include <vector>
#include "GameBoard.h"

/**
 * @file GameBoard.cpp
 * @brief Implementation file for the game board class.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

/**
 * @brief Constructs a GameBoard object with default settings.
 */
GameBoard::GameBoard()
    : tileSize(40),
      boardSize(11),
      customColor1(sf::Color(249, 249, 249)),
      customColor2(sf::Color(241, 241, 241)) {

    // Ivey path
    iveyPath.push_back(sf::Vector2f(220, 420)); // start
    iveyPath.push_back(sf::Vector2f(220, 380)); // crossing 1
    iveyPath.push_back(sf::Vector2f(260, 380));
    iveyPath.push_back(sf::Vector2f(300, 380));
    iveyPath.push_back(sf::Vector2f(340, 380));
    iveyPath.push_back(sf::Vector2f(380, 380));
    iveyPath.push_back(sf::Vector2f(380, 340));
    iveyPath.push_back(sf::Vector2f(380, 300));
    iveyPath.push_back(sf::Vector2f(380, 260));
    iveyPath.push_back(sf::Vector2f(340, 260));
    iveyPath.push_back(sf::Vector2f(300, 260));
    iveyPath.push_back(sf::Vector2f(260, 260)); // crossing 2
    iveyPath.push_back(sf::Vector2f(260, 220));
    iveyPath.push_back(sf::Vector2f(260, 180));
    iveyPath.push_back(sf::Vector2f(300, 180));
    iveyPath.push_back(sf::Vector2f(340, 180));
    iveyPath.push_back(sf::Vector2f(380, 180));
    iveyPath.push_back(sf::Vector2f(380, 140));
    iveyPath.push_back(sf::Vector2f(380, 100));
    iveyPath.push_back(sf::Vector2f(340, 100));
    iveyPath.push_back(sf::Vector2f(300, 100));
    iveyPath.push_back(sf::Vector2f(260, 100));
    iveyPath.push_back(sf::Vector2f(220, 100));
    iveyPath.push_back(sf::Vector2f(180, 100)); //end

    // Western path
    westernPath.push_back(sf::Vector2f(220, 420)); // start
    westernPath.push_back(sf::Vector2f(220, 380)); // crossing 1
    westernPath.push_back(sf::Vector2f(180, 380));
    westernPath.push_back(sf::Vector2f(140, 380));
    westernPath.push_back(sf::Vector2f(100, 380));
    westernPath.push_back(sf::Vector2f(60, 380));
    westernPath.push_back(sf::Vector2f(60, 340));
    westernPath.push_back(sf::Vector2f(60, 300));
    westernPath.push_back(sf::Vector2f(60, 260));
    westernPath.push_back(sf::Vector2f(60, 220));
    westernPath.push_back(sf::Vector2f(100, 220));
    westernPath.push_back(sf::Vector2f(140, 220));
    westernPath.push_back(sf::Vector2f(180, 220));
    westernPath.push_back(sf::Vector2f(180, 260));
    westernPath.push_back(sf::Vector2f(220, 260));
    westernPath.push_back(sf::Vector2f(260, 260)); // crossing 2
    westernPath.push_back(sf::Vector2f(260, 220));
    westernPath.push_back(sf::Vector2f(260, 180));
    westernPath.push_back(sf::Vector2f(300, 180));
    westernPath.push_back(sf::Vector2f(340, 180));
    westernPath.push_back(sf::Vector2f(380, 180));
    westernPath.push_back(sf::Vector2f(380, 140));
    westernPath.push_back(sf::Vector2f(380, 100));
    westernPath.push_back(sf::Vector2f(340, 100));
    westernPath.push_back(sf::Vector2f(300, 100));
    westernPath.push_back(sf::Vector2f(260, 100));
    westernPath.push_back(sf::Vector2f(220, 100));
    westernPath.push_back(sf::Vector2f(180, 100)); //end

    // Event spaces
    eventSpaces.push_back(sf::Vector2f(140, 380)); // first Western square - missing others
    eventSpaces.push_back(sf::Vector2f(340, 380)); // first Ivey
    eventSpaces.push_back(sf::Vector2f(380, 300)); // second Ivey
    eventSpaces.push_back(sf::Vector2f(60, 300));
    eventSpaces.push_back(sf::Vector2f(140, 220));
    eventSpaces.push_back(sf::Vector2f(300, 180));
    eventSpaces.push_back(sf::Vector2f(380, 140));
}

/**
 * @brief Gets the Ivey path vector.
 * @return Const reference to the Ivey path vector.
 */
const std::vector<sf::Vector2f>& GameBoard::getIveyPath() const {
    return iveyPath;
}

/**
 * @brief Gets the Western path vector.
 * @return Const reference to the Western path vector.
 */
const std::vector<sf::Vector2f>& GameBoard::getWesternPath() const {
    return westernPath;
}

/**
 * @brief Gets the event spaces vector.
 * @return Const reference to the event spaces vector.
 */
const std::vector<sf::Vector2f>& GameBoard::getEventSpaces() const {
    return eventSpaces;
}

/**
 * @brief Draws the game board on the specified SFML RenderWindow.
 * @param window SFML RenderWindow to draw the game board on.
 */
void GameBoard::draw(sf::RenderWindow &window) {
    sf::Color Crossing(123, 123, 123);
    sf::Color Road(90, 90, 90);
    sf::Color WesternPurple(79, 38, 131);
    sf::Color IveyGreen(3, 70, 56);
    sf::Color EventColour(67, 87, 31);

    sf::Texture background;
    if (!background.loadFromFile("westernUniversity.jpg")) {
        // Handle error if the image can't be loaded
    }

    sf::Sprite backgroundImage;
    backgroundImage.setTexture(background);

    float scale = 0.9f;
    backgroundImage.setScale(scale, scale);
    window.draw(backgroundImage);

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            sf::RectangleShape square(sf::Vector2f(tileSize, tileSize));
            square.setPosition(i * tileSize, j * tileSize);

            if ((i + j) % 2 == 0) {
                square.setFillColor(sf::Color::Transparent);
            } else {
                square.setFillColor(sf::Color::Transparent);
            }

            // Start Tile
            if (i == 5 && j == boardSize - 1) {
                square.setFillColor(sf::Color::Green);
            }

            // End Tile
            if (j == 2 && i >= 3 && i <= 4) {
                square.setFillColor(sf::Color::Red);
            }

            if ((j == 6 && i == 6) || (j == 9 && i == 5)) {
                square.setFillColor(Crossing);
            }

            if ((j == 2 && i >= 5 && i <= 9) ||
                (j == 3 && i == 9) ||
                (j == 4 && i >= 6 && i <= 9) ||
                (j == 5 && i == 6)) {
                square.setFillColor(Road);
            }

            if ((j == 5 && i >= 1 && i <= 4) ||
                (j == 6 && i == 1) ||
                (j == 6 && i >= 4 && i <= 5) ||
                (j == 7 && i == 1) ||
                (j == 8 && i == 1) ||
                (j == 9 && i >= 1 && i <= 4)) {
                square.setFillColor(WesternPurple);
            }

            if ((j == 6 && i >= 7 and i <= 9) ||
                (j == 7 and i == 9) ||
                (j == 8 and i == 9) ||
                (j == 9 and i >= 6 and i <= 9)) {
                square.setFillColor(IveyGreen);
            }

            if ((j == 3 && i == 9) || // road
                (j == 4 && i == 7) || // road
                (j == 7 && i == 1) || // Western
                (j == 5 && i == 3) || // Western
                (j == 9 && i == 3) || // Western
                (j == 7 && i == 9) || // Ivey
                (j == 9 && i == 8)    // Ivey
            ) {
                square.setFillColor(EventColour);
            }

            window.draw(square);
        }
    }
}
