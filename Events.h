#ifndef EVENTS_H
#define EVENTS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

/**
 * @file Events.h
 * @brief Header file defining functions related to in-game events.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

namespace events {

    /**
     * @brief Displays an event popup window to the player.
     * @param window SFML RenderWindow to display the event popup.
     * @param message Message to be displayed in the popup window.
     * @param player Player object representing the game state.
     */
    void playerEvent(sf::RenderWindow& window, const std::string& message, Player& player);

} // namespace events

#endif // EVENTS_H
