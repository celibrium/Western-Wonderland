#ifndef RESOURCEDISPLAY_H
#define RESOURCEDISPLAY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h" // Include the Player class

/**
 * @file ResourceDisplay.h
 * @brief Header file for displaying the player's resources in the game.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

namespace ResourceDisplay {

    /**
     * @brief Displays the player's resources on the game window.
     * @param window SFML RenderWindow to display the resource information.
     * @param player Player object representing the game state.
     * @param message Additional message to be displayed.
     */
    void resourceDisplay(sf::RenderWindow& window, const Player& player, const std::string& message);
};

#endif // RESOURCEDISPLAY_H
