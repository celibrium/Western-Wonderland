#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Wheel.h"

/**
 * @file Wheel.cpp
 * @brief Implementation file for the Wheel class representing a spinning wheel game.
 */

/**
 * @brief Default constructor for the Wheel class.
 * Initializes the wheel with numbers and loads the font.
 */
Wheel::Wheel() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Initialize the wheel with numbers from 1 to 5
    for (int i = 1; i <= 5; ++i) {
        numbers.push_back(i);
    }

    // Load font for text rendering
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }
}

/**
 * @brief Spins the wheel and returns the result.
 * @param window SFML RenderWindow for drawing the wheel animation.
 * @return Pair containing the spin result (number) and arrow angle.
 */
std::pair<int, float> Wheel::SpinWheel(sf::RenderWindow& window) {
    int totalRotations = 5 * numbers.size();
    totalRotations += std::rand() % numbers.size();

    // Spin the wheel animation
    for (int i = 0; i < totalRotations; ++i) {
        DrawWheel(i * (360.0f / numbers.size()), window);
        window.display();
        sf::sleep(sf::milliseconds(50));
    }

    // Calculate the arrow angle and spin result
    float arrowAngle = totalRotations * (360.0f / numbers.size());
    int spinResult = GetSpinResult(totalRotations % numbers.size());

    return std::make_pair(spinResult, arrowAngle);
}

/**
 * @brief Retrieves the spin result based on the wheel index.
 * @param index Index of the wheel segment where the arrow stops.
 * @return Spin result (number).
 */
int Wheel::GetSpinResult(int index) {
    return numbers[index];
}

/**
 * @brief Draws the wheel with segments and the spinning arrow.
 * @param arrowAngle Angle of the spinning arrow.
 * @param window SFML RenderWindow for drawing.
 */
void Wheel::DrawWheel(float arrowAngle, sf::RenderWindow& window) {
    float angleStep = 360.0f / numbers.size();
    float currentAngle = 0.0f;

    // Define colors for wheel segments
    sf::Color colors[] = {sf::Color(200, 150, 255), sf::Color(34, 139, 34), sf::Color(192, 192, 192)};

    // Draw wheel segments and associated numbers
    for (size_t i = 0; i < numbers.size(); ++i) {
        sf::ConvexShape segment(3);
        segment.setPoint(0, sf::Vector2f(90.0f, 90.0f));
        segment.setPoint(1, sf::Vector2f(90.0f + 70.0f * std::cos(currentAngle * 3.14159265 / 180),
                                          90.0f + 70.0f * std::sin(currentAngle * 3.14159265 / 180)));
        segment.setPoint(2, sf::Vector2f(90.0f + 70.0f * std::cos((currentAngle + angleStep) * 3.14159265 / 180),
                                          90.0f + 70.0f * std::sin((currentAngle + angleStep) * 3.14159265 / 180)));
        segment.setFillColor(colors[i % 3]);

        window.draw(segment);

        sf::Text numberText(std::to_string(numbers[i]), font, 20);
        numberText.setFillColor(sf::Color::Black);
        float x = 90.0f + 32.0f * std::cos((currentAngle + angleStep / 2) * 3.14159265 / 180);
        float y = 90.0f + 32.0f * std::sin((currentAngle + angleStep / 2) * 3.14159265 / 180);

        sf::FloatRect textBounds = numberText.getLocalBounds();
        numberText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        numberText.setPosition(x, y);

        window.draw(numberText);

        currentAngle += angleStep;
    }

    // Draw the spinning arrow
    sf::ConvexShape arrow(3);
    arrow.setPoint(0, sf::Vector2f(90.0f, 90.0f));
    arrow.setPoint(1, sf::Vector2f(90.0f + 70.0f * std::cos(arrowAngle * 3.14159265 / 180),
                                    90.0f + 70.0f * std::sin(arrowAngle * 3.14159265 / 180)));
    arrow.setPoint(2, sf::Vector2f(90.0f + 70.0f * std::cos((arrowAngle + angleStep) * 3.14159265 / 180),
                                    90.0f + 70.0f * std::sin((arrowAngle + angleStep) * 3.14159265 / 180)));
    arrow.setFillColor(sf::Color(238, 227, 224, 128));

    window.draw(arrow);
}
