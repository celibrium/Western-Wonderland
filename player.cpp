#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>  // For std::sqrt, std::pow
#include "Player.h"
#include <iostream>

/**
 * @file Player.cpp
 * @brief Implementation file for the Player class representing the game player.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

/**
 * @brief Constructs a Player object with specified attributes.
 * @param spaces Vector of positions representing the player's path.
 * @param color Color of the player's marker.
 * @param radius Radius of the player's marker.
 */
Player::Player(const std::vector<sf::Vector2f>& spaces, sf::Color color, float radius)
    : path(spaces), currentSpaceIndex(0), targetSpaceIndex(0), isMoving(false), moveDelay(0.3f), eventTriggered(false) {
    marker.setRadius(radius);
    marker.setFillColor(color);
    marker.setOrigin(radius, radius);
    marker.setPosition(path[currentSpaceIndex]);
    GPA = 0;
    happiness = 0;
    debt = 0;
}

/**
 * @brief Moves the player a specified number of spaces.
 * @param spaces Number of spaces to move.
 */
void Player::move(int spaces) {
    if (currentSpaceIndex + spaces <= path.size() - 1) {
        targetSpaceIndex = currentSpaceIndex + spaces;
    } else {
        targetSpaceIndex = path.size() - 1;
    }
    isMoving = true;
    moveClock.restart();
    eventTriggered = false;
}

/**
 * @brief Checks if the player has just finished moving.
 * @return True if the player has just finished moving, false otherwise.
 */
bool Player::justMoved() {
    if (!isMoving) {
        return true;
    }
    return false;
}

/**
 * @brief Updates the player's position during movement.
 */
void Player::update() {
    if (isMoving && moveClock.getElapsedTime().asSeconds() >= moveDelay) {
        if (currentSpaceIndex != targetSpaceIndex) {
            currentSpaceIndex++;
            marker.setPosition(path[currentSpaceIndex]);
            moveClock.restart();
        } else {
            isMoving = false;
        }
    }
}

/**
 * @brief Checks if the player is on an event space.
 * @param eventSpaces Vector of positions representing event spaces.
 * @return True if the player is on an event space, false otherwise.
 */
bool Player::onEvent(const std::vector<sf::Vector2f>& eventSpaces) {
    if (!eventTriggered) {
        for (const auto& eventSpace : eventSpaces) {
            if (path[currentSpaceIndex] == eventSpace) {
                eventTriggered = true;
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Draws the player on the SFML RenderWindow.
 * @param window SFML RenderWindow to draw the player on.
 */
void Player::draw(sf::RenderWindow& window) {
    window.draw(marker);
}

/**
 * @brief Gets the current position of the player.
 * @return Vector representing the player's current position.
 */
sf::Vector2f Player::getPosition() const {
    return marker.getPosition();
}

/**
 * @brief Sets the major of the player.
 * @param value Major value to set.
 */
void Player::setMajor(int value) {
    major = value;
}

/**
 * @brief Gets the major of the player.
 * @return Major value of the player.
 */
int Player::getMajor() const {
    return GPA; // This should be "return major;" instead of "return GPA;"
}

/**
 * @brief Sets the path for the player to follow.
 * @param spaces Vector of positions representing the player's path.
 */
void Player::setPath(const std::vector<sf::Vector2f>& spaces) {
    path = spaces;
}

/**
 * @brief Increases or decreases the player's debt.
 * @param amount Amount to change the debt by.
 */
void Player::setDebt(int amount) {
    debt += amount;
}

/**
 * @brief Increases or decreases the player's happiness.
 * @param amount Amount to change the happiness by.
 */
void Player::setHappiness(int amount) {
    happiness += amount;
}

/**
 * @brief Increases or decreases the player's GPA, clamped between 0 and 4.
 * @param amount Amount to change the GPA by.
 */
void Player::setGPA(int amount) {
    GPA += amount;
}

/**
 * @brief Gets the current debt of the player.
 * @return Current debt of the player.
 */
int Player::getDebt() const {
    return debt;
}

/**
 * @brief Gets the current happiness of the player.
 * @return Current happiness of the player.
 */
int Player::getHappiness() const {
    return happiness;
}

/**
 * @brief Gets the current GPA of the player.
 * @return Current GPA of the player.
 */
int Player::getGPA() const {
    return GPA;
}

/**
 * @brief Checks if the player has reached the end of the path.
 * @return True if the player has finished, false otherwise.
 */
bool Player::finished() {
    return currentSpaceIndex == path.size() - 1;
}
