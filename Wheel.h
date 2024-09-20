#ifndef WHEEL_H
#define WHEEL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

/**
 * @file Wheel.h
 * @brief Header file for the Wheel class, representing a spinning wheel game.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

/**
 * @class Wheel
 * @brief Represents a spinning wheel game.
 */
class Wheel {

public:
    /**
     * @brief Default constructor for the Wheel class.
     */
    Wheel();

    /**
     * @brief Spins the wheel and returns the result.
     * @param window SFML RenderWindow for drawing the wheel.
     * @return A pair containing the index and angle of the wheel result.
     */
    std::pair<int, float> SpinWheel(sf::RenderWindow& window);

    /**
     * @brief Gets the spin result at a specified index.
     * @param index Index of the spin result to retrieve.
     * @return The spin result at the specified index.
     */
    int GetSpinResult(int index);

    /**
     * @brief Draws the spinning wheel with an arrow indicating the result.
     * @param arrowAngle Angle of the arrow indicating the wheel result.
     * @param window SFML RenderWindow for drawing the wheel.
     */
    void DrawWheel(float arrowAngle, sf::RenderWindow& window);

    /**
     * @brief Runs the spinning wheel game.
     */
    void Run();

private:
    sf::RenderWindow window; ///< SFML RenderWindow for drawing the wheel.
    sf::Font font;           ///< Font for text rendering.
    std::vector<int> numbers; ///< Vector containing the wheel result numbers.

};

#endif // WHEEL_H
