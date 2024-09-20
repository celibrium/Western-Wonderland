#ifndef GRADUATION_H
#define GRADUATION_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

/**
 * @file Graduation.h
 * @brief Header file for handling graduation events and determining the winner.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

namespace Graduation {

    /**
     * @brief Displays a graduation event popup for two players and determines the winner.
     * @param window SFML RenderWindow to display the graduation event popup.
     * @param message Message to be displayed in the popup window.
     * @param player1 Player object representing the first player's game state.
     * @param player2 Player object representing the second player's game state.
     */
    void graduationEvent(sf::RenderWindow& window, const std::string& message, Player& player1, Player& player2);

    /**
     * @brief Determines the winner based on the scores of two players.
     * @param P1score Score of the first player.
     * @param P2score Score of the second player.
     * @return A string indicating the winner.
     */
    std::string Winner(int P1score, int P2score);

} // namespace Graduation

#endif // GRADUATION_H
