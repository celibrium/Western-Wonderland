#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @file GameBoard.h
 * @brief Header file defining the GameBoard class for managing the game board.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

/**
 * @class GameBoard
 * @brief Represents the game board and its properties.
 */
class GameBoard {
private:
    std::vector<sf::Vector2f> spaces; ///< Coordinates for each space on the board
    // Additional properties, like textures, tiles, etc., can be added here

    // Constants
    const int tileSize;             ///< Size of each tile in pixels.
    const int boardSize;            ///< Size of the game board (number of tiles in each dimension).
    const sf::Color customColor1;   ///< Custom color 1.
    const sf::Color customColor2;   ///< Custom color 2.

    std::vector<sf::Vector2f> iveyPath;     ///< Coordinates for spaces on the Ivey path.
    std::vector<sf::Vector2f> westernPath;  ///< Coordinates for spaces on the Western path.
    std::vector<sf::Vector2f> eventSpaces;  ///< Coordinates for spaces where events can occur.

public:
    /**
     * @brief Constructor for the GameBoard class.
     */
    GameBoard();

    /**
     * @brief Get the coordinates of spaces on the Ivey path.
     * @return Vector containing coordinates of spaces on the Ivey path.
     */
    const std::vector<sf::Vector2f>& getIveyPath() const;

    /**
     * @brief Get the coordinates of spaces on the Western path.
     * @return Vector containing coordinates of spaces on the Western path.
     */
    const std::vector<sf::Vector2f>& getWesternPath() const;

    /**
     * @brief Get the coordinates of spaces where events can occur.
     * @return Vector containing coordinates of spaces where events can occur.
     */
    const std::vector<sf::Vector2f>& getEventSpaces() const;

    /**
     * @brief Draw the game board on the specified SFML RenderWindow.
     * @param window SFML RenderWindow on which to draw the game board.
     */
    void draw(sf::RenderWindow& window);

    // bool isSpecialSpace(int index) const;
};

#endif // GAMEBOARD_H
