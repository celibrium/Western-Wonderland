#include <iostream>
#include <SFML/Graphics.hpp>
#include "majorSelection.h"

/**
 * @file majorSelection.cpp
 * @brief Implementation file for handling major selection events.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

/**
 * @brief Displays a major selection popup window to the player.
 * @param window SFML RenderWindow to display the major selection popup.
 * @param message Message to be displayed in the popup window.
 * @return 1 if the player selects Ivey, 0 if the player selects Western, false if the window is closed.
 */
int majorSelection::majorEvent(sf::RenderWindow& window, const std::string& message) {
    // Load popup image
    sf::Texture popupImage;
    if (!popupImage.loadFromFile("westernUniversity.jpg")) {
        std::cerr << "Image failed to load" << std::endl;
    }

    // Create a sprite for the popup background
    sf::Sprite popupSprite;
    popupSprite.setTexture(popupImage);

    float scale = 0.9f; // Adjust this value to control the size
    popupSprite.setScale(scale, scale);

    // Load Western logo button image
    sf::Texture westernButton;
    if (!westernButton.loadFromFile("westernLogo.png")) {
        std::cerr << "Western image failed to load" << std::endl;
    }

    // Create a sprite for the Western logo button
    sf::Sprite westernSprite;
    westernSprite.setTexture(westernButton);

    // Load Ivey logo button image
    sf::Texture iveyButton;
    if (!iveyButton.loadFromFile("iveyLogo.png")) {
        std::cerr << "Ivey image failed to load" << std::endl;
    }

    // Create a sprite for the Ivey logo button
    sf::Sprite iveySprite;
    iveySprite.setTexture(iveyButton);

    float iveyScale = 0.3f; // Adjust this value to control the size
    iveySprite.setScale(iveyScale, iveyScale);

    // Load fonts
    sf::Font font;
    if (!font.loadFromFile("Montserrat Medium 500.ttf")) {
        std::cerr << "Montserrat font failed to load" << std::endl;
    }
    sf::Font arialFont;
    if (!arialFont.loadFromFile("Arial.ttf")) {
        std::cerr << "Arial font failed to load" << std::endl;
    }

    // Create text for different options
    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    sf::Text text2;
    text2.setFont(font);
    text2.setString("Ivey - Press I");
    text2.setCharacterSize(24);
    text2.setFillColor(sf::Color(48, 93, 44));

    sf::Text text3;
    text3.setFont(font);
    text3.setString("Western - Press W");
    text3.setCharacterSize(24);
    text3.setFillColor(sf::Color(91, 10, 125));

    // Ensure the popup screen is smaller than the main window
    float popupWidth = window.getSize().x * 0.75f;
    float popupHeight = window.getSize().y * 0.9f;

    // Position of the center of the popup
    float popupX = (window.getSize().x - popupWidth) / 2;
    float popupY = (window.getSize().y - popupHeight) / 2;

    // Place the text on the screen with ideal positioning
    text.setPosition(popupX + 20, popupY);
    text2.setPosition(popupX + 200, popupY + 290);
    westernSprite.setPosition(10, 100);
    iveySprite.setPosition(popupX + 190, popupY + 150);
    text3.setPosition(popupX - 30, popupY + 290);

    // Create the popup background
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(popupWidth, popupHeight));
    background.setFillColor(sf::Color::Transparent);
    background.setPosition((window.getSize().x - background.getSize().x) / 2, (window.getSize().y - background.getSize().y) / 2);

    while (window.isOpen()) {
        window.clear();  // Clear the window at the beginning of each loop
        window.draw(popupSprite);
        window.draw(background);
        window.draw(westernSprite);
        window.draw(iveySprite);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            }

            // Check for key presses to select a major
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::I) {
                    return 1; // Ivey selected
                }
                else if (event.key.code == sf::Keyboard::W) {
                    return 0; // Western selected
                }
            }
        }  

        window.display();
    }
    return false;
}
