#ifndef MAJORSELECTION_H
#define MAJORSELECTION_H

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @file majorSelection.h
 * @brief Header file for handling major selection events.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

namespace majorSelection {

    /**
     * @brief Displays a major selection event popup window to the player.
     * @param window SFML RenderWindow to display the major selection popup.
     * @param message Message to be displayed in the popup window.
     * @return Integer representing the player's chosen major.
     */
    int majorEvent(sf::RenderWindow& window, const std::string& message);

} // namespace majorSelection

#endif // MAJORSELECTION_H
