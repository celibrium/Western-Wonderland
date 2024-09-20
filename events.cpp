#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Events.h"

/**
 * @file events.cpp
 * @brief Implementation file for handling in-game events.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

/**
 * @brief Represents an in-game event with associated attributes.
 */
struct Event {
    std::string description; ///< Description of the event.
    int happinessScore;      ///< Impact on player's happiness.
    int debtScore;           ///< Impact on player's debt.
    int gpaScore;            ///< Impact on player's GPA.
};

/**
 * @brief Reads an event from a file.
 * @param file Input file stream.
 * @return Event object containing the details of the read event.
 */
Event readEvent(std::ifstream& file);

/**
 * @brief Wraps text to fit within a specified width.
 * @param str Input string to be wrapped.
 * @param font Font for text rendering.
 * @param charSize Character size for text rendering.
 * @param maxLineWidth Maximum width for a line.
 * @return Wrapped text as a string.
 */
std::string wrapText(const std::string& str, const sf::Font& font, unsigned int charSize, unsigned int maxLineWidth);

namespace events {

    /**
     * @brief Displays an event popup window to the player.
     * @param window SFML RenderWindow to display the event popup.
     * @param message Message to be displayed in the popup window.
     * @param player Player object representing the game state.
     */
    void playerEvent(sf::RenderWindow& window, const std::string& message, Player& player);
}

Event readEvent(std::ifstream& file) {
    Event event;
    getline(file, event.description); // Read event description

    // Read the three numbers
    file >> event.happinessScore >> event.debtScore >> event.gpaScore;
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip to the next line

    return event;
}

std::string wrapText(const std::string& str, const sf::Font& font, unsigned int charSize, unsigned int maxLineWidth) {
    std::istringstream words(str);
    std::string word;
    std::string wrappedText;
    std::string line;

    while (words >> word) {
        sf::Text tempText(line + word, font, charSize);
        if (tempText.getLocalBounds().width > maxLineWidth) {
            wrappedText += line + "\n";
            line = "";
        }
        line += word + " ";
    }
    wrappedText += line;  // Add the last line
    return wrappedText;
}

void events::playerEvent(sf::RenderWindow& window, const std::string& message, Player& player) {
    // Load fonts
    sf::Font font;
    if (!font.loadFromFile("Montserrat Medium 500.ttf")) {
        std::cerr << "Montserrat font failed to load" << std::endl;
    }

    // Read event text from file and store in a vector
    std::ifstream file("events.txt");
    std::vector<Event> events;
    while (file.peek() != EOF) {
        events.push_back(readEvent(file));
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip empty lines between events
    }
    file.close();

    // Randomly select an event
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, events.size() - 1);
    Event selectedEvent = events[distrib(gen)];

    // Apply text wrapping to the selected event description
    const unsigned int maxLineWidth = window.getSize().x * 0.65f;  // Maximum line width in pixels
    const unsigned int charSize = 24;       // Character size for the font
    std::string wrappedDescription = wrapText(selectedEvent.description, font, charSize, maxLineWidth);

    // Calculate position and size for popup window and text
    float popupWidth = window.getSize().x * 0.75f;
    float popupHeight = window.getSize().y * 0.9f;
    float popupX = (window.getSize().x - popupWidth) / 2;
    float popupY = (window.getSize().y - popupHeight) / 2;

    // Create popup background
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(popupWidth, popupHeight));
    background.setFillColor(sf::Color(91, 10, 125));
    background.setPosition(popupX, popupY);

    // Display selected event description
    sf::Text text;
    text.setFont(font);
    text.setString(wrappedDescription);
    text.setCharacterSize(charSize);
    text.setFillColor(sf::Color::White);
    text.setPosition(popupX + 20, popupY + 60);

    // Display resources associated with the event
    sf::Text text2;
    text2.setFont(font);
    text2.setString("Happiness: " + std::to_string(selectedEvent.happinessScore) +
                   "\nDebt: " + std::to_string(selectedEvent.debtScore) +
                   "\nGPA: " + std::to_string(selectedEvent.gpaScore));
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(popupX + 20, popupY + 300);

    // Create a close button
    sf::RectangleShape closeButton(sf::Vector2f(50, 50));
    closeButton.setFillColor(sf::Color::Red);
    closeButton.setPosition(window.getSize().x - 60, 10); // Adjust position as needed

    bool closeEventWindow = false;  // Flag to control the event window closure

    // Get the scores
    player.setHappiness(player.getHappiness() + selectedEvent.happinessScore);
    player.setDebt(player.getDebt() + selectedEvent.debtScore);
    player.setGPA(player.getGPA() + selectedEvent.gpaScore);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Check if the close button is clicked
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (closeButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        closeEventWindow = true;  // Set the flag to close the event window
                    }
                }
            }
        }

        if (closeEventWindow) {
            break;  // Exit the loop to close the event window
        }

        window.draw(background);
        window.draw(text);
        window.draw(text2);
        window.draw(closeButton);
        window.display();
    }
}
