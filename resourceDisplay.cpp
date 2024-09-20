#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourceDisplay.h"
#include "Player.h"

/**
 * @file ResourceDisplay.cpp
 * @brief Implementation file for displaying player resources and information.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

/**
 * @brief Displays player resources and information in a popup window.
 * @param window SFML RenderWindow to display the resource popup.
 * @param player Player object representing the game state.
 * @param message Message to be displayed in the popup window.
 */
void ResourceDisplay::resourceDisplay(sf::RenderWindow& window, const Player& player, const std::string& message) {
    sf::Font font;
    if (!font.loadFromFile("Montserrat Medium 500.ttf")) {
        std::cerr << "Montserrat font failed to load" << std::endl;
    }
    sf::Font arialFont;  // Placeholder for Arial font
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Arial font failed to load" << std::endl;
    }

    // For graduation text
    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    // Player information text
    sf::Text text2;
    text2.setFont(font);
    text2.setString("Happiness: " + std::to_string(player.getHappiness()) +
                    "\nDebt: " + std::to_string(player.getDebt()) +
                    "\nGPA: " + std::to_string(player.getGPA()));
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::White);

    // Ensures the popup screen is smaller than the main window
    float popupWidth = window.getSize().x * 0.75f;
    float popupHeight = window.getSize().y * 0.9f;

    // Position of the center of the popup
    float popupX = (window.getSize().x - popupWidth) / 2;
    float popupY = (window.getSize().y - popupHeight) / 2;

    // Place the text on the screen with ideal positioning
    text.setPosition(popupX + 100, popupY + 10);
    text2.setPosition(popupX, popupY + 60);

    // Makes the popup screen
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(popupWidth, popupHeight));
    background.setFillColor(sf::Color(91, 10, 125));
    background.setPosition((window.getSize().x - background.getSize().x) / 2, (window.getSize().y - background.getSize().y) / 2);

    bool closeEventWindow = false;  // Flag to control the event window closure

    // Popup should be opened for 15 seconds and then will close
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Check if close button (X key) is pressed
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) {
                closeEventWindow = true;  // Set the flag to close the event window
            }
        }

        if (closeEventWindow) {
            break;  // Exit the loop to close the event window
        }

        window.draw(background);
        window.draw(text);
        window.draw(text2);
        window.display();
    }
}
