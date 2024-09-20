#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @file Game.h
 * @brief Header file defining the game start functionality.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

namespace gamestart {

    /**
     * @brief Initiates the game and displays the main menu.
     * @param window SFML RenderWindow for the game.
     * @return True if the game started successfully, false otherwise.
     */
    bool gamestart(sf::RenderWindow& window);

} // namespace gamestart

#endif // GAME_H
