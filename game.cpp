#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.h"

/**
 * @file gamestart.cpp
 * @brief Implementation file for the game start popup functionality.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

namespace gamestart {

    /**
     * @brief Displays the game start popup and handles user interaction.
     * @param window SFML RenderWindow to display the game start popup.
     * @return True if the user clicks the start button, false if the window is closed or an error occurs.
     */
    bool gamestart(sf::RenderWindow& window);
}

bool gamestart::gamestart(sf::RenderWindow& window) {
    // Load the popup image
    sf::Texture popupImage;
    if (!popupImage.loadFromFile("westernUniversity.jpg")) {
        std::cerr << "Image failed to load" << std::endl;
    }

    // Create a sprite for the popup image
    sf::Sprite popupSprite(popupImage);
    float scale = 0.9f;
    popupSprite.setScale(scale, scale);

    // Load font for text
    sf::Font font;
    if (!font.loadFromFile("Lobster.ttf")) {
        std::cerr << "Lobster font failed to load" << std::endl;
    }

    // Create welcome text
    sf::Text welcomeText("Welcome \n to \n Western \n Wonderland!", font, 50);
    welcomeText.setFillColor(sf::Color::Black);
    welcomeText.setPosition(window.getSize().x / 2.0f, window.getSize().y / 3.0f);
    welcomeText.setOrigin(welcomeText.getLocalBounds().width / 2.0f, welcomeText.getLocalBounds().height / 2.0f);

    // Create background for the popup
    sf::RectangleShape background(sf::Vector2f(window.getSize().x * 0.75f, window.getSize().y * 0.9f));
    background.setFillColor(sf::Color::Transparent);
    background.setPosition((window.getSize().x - background.getSize().x) / 2, ((window.getSize().y - background.getSize().y) / 2) + 50);

    // Create start button
    sf::RectangleShape startButton(sf::Vector2f(100, 50));
    startButton.setFillColor(sf::Color(200, 150, 255));
    startButton.setPosition((window.getSize().x - startButton.getSize().x) / 2, (window.getSize().y - startButton.getSize().y) / 2 + background.getSize().y / 2 - 70);

    // Create text for the start button
    sf::Text buttonText("Start", font, 20);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(startButton.getPosition().x + 25, startButton.getPosition().y + 15);

    // Main loop for the popup
    while (window.isOpen()) {
        window.clear();

        // Draw elements
        window.draw(popupSprite);
        window.draw(background);
        window.draw(welcomeText);
        window.draw(startButton);
        window.draw(buttonText);

        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            }
        }

        // Check if the start button is clicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                return true;  // Close the pop-up when the start button is clicked
            }
        }

        window.display();
    }

    return false;
}
