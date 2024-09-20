#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

/**
 * @file Player.h
 * @brief Header file for the Player class representing the game's player character.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

/**
 * @class Player
 * @brief Represents the player character in the game.
 */
class Player {
private:
    sf::CircleShape marker; ///< Shape representing the player's position on the game board.
    bool isMoving;          ///< Flag indicating whether the player is currently in motion.
    float moveSpeed;        ///< Speed of player movement.

    int major;              ///< Player's chosen major.

    int currentSpaceIndex;  ///< Index of the current space on the game board.
    int targetSpaceIndex;   ///< Index of the target space for movement.

    bool moved;             ///< Flag indicating whether the player has moved.

    sf::Clock moveClock;    ///< Clock to manage movement delay.
    float moveDelay;        ///< Duration of movement delay in seconds.

    // Resources
    int debt;               ///< Player's debt resource.
    int happiness;          ///< Player's happiness resource.
    int GPA;                ///< Player's GPA resource.

    std::vector<sf::Vector2f> path; ///< Path representing the player's movement trajectory.

    bool eventTriggered;    ///< Flag indicating whether an event has been triggered.

public:
    /**
     * @brief Constructor for the Player class.
     * @param spaces Vector of positions representing the game board spaces.
     * @param color Color of the player's marker.
     * @param radius Radius of the player's marker.
     */
    Player(const std::vector<sf::Vector2f>& spaces, sf::Color color, float radius = 3.0f);

    /**
     * @brief Initiates movement towards a target space on the game board.
     * @param targetIndex Index of the target space.
     */
    void move(int targetIndex);

    /**
     * @brief Updates the player's state, including movement and resource management.
     */
    void update();

    /**
     * @brief Draws the player on the specified SFML RenderWindow.
     * @param window SFML RenderWindow to draw the player on.
     */
    void draw(sf::RenderWindow& window);

    // void setPosition(const sf::Vector2f& position);

    /**
     * @brief Retrieves the current position of the player.
     * @return Current position as an SFML Vector2f.
     */
    sf::Vector2f getPosition() const;

    /**
     * @brief Checks if the player is on an event space.
     * @param eventSpaces Vector of positions representing event spaces.
     * @return True if the player is on an event space, false otherwise.
     */
    bool onEvent(const std::vector<sf::Vector2f>& eventSpaces);

    /**
     * @brief Sets the player's chosen major.
     * @param value Major value to set.
     */
    void setMajor(int value);

    /**
     * @brief Retrieves the player's chosen major.
     * @return Player's major.
     */
    int getMajor() const;

    /**
     * @brief Sets the player's movement path.
     * @param spaces Vector of positions representing the movement path.
     */
    void setPath(const std::vector<sf::Vector2f>& spaces);

    /**
     * @brief Checks if the player has just moved.
     * @return True if the player has just moved, false otherwise.
     */
    bool justMoved();

    // Resource management methods

    /**
     * @brief Sets the player's debt resource.
     * @param amount Debt amount to set.
     */
    void setDebt(int amount);

    /**
     * @brief Sets the player's happiness resource.
     * @param amount Happiness amount to set.
     */
    void setHappiness(int amount);

    /**
     * @brief Sets the player's GPA resource.
     * @param amount GPA amount to set.
     */
    void setGPA(int amount);

    // Getters for resources

    /**
     * @brief Retrieves the player's debt resource.
     * @return Player's debt amount.
     */
    int getDebt() const;

    /**
     * @brief Retrieves the player's happiness resource.
     * @return Player's happiness amount.
     */
    int getHappiness() const;

    /**
     * @brief Retrieves the player's GPA resource.
     * @return Player's GPA amount.
     */
    int getGPA() const;

    /**
     * @brief Checks if the player has reached the end of the game.
     * @return True if the player has finished, false otherwise.
     */
    bool finished();
};

#endif // PLAYER_H
