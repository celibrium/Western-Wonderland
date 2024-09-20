#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graduation.h"

/**
 * @file Graduation.cpp
 * @brief Implementation file for handling graduation events in the game.
 * @author Ansel Zeng, Kelly Guo, Stanley Cao, Charmaine Lee, Nicole Moskovitch
 */

/**
 * @brief Displays the graduation event popup window.
 * @param window SFML RenderWindow to display the graduation event popup.
 * @param message Message to be displayed in the popup window.
 * @param player1 First player object representing the game state.
 * @param player2 Second player object representing the game state.
 */
void Graduation::graduationEvent(sf::RenderWindow& window, const std::string& message, Player& player1, Player& player2) {
    sf::Font font;
    if (!font.loadFromFile("Montserrat Medium 500.ttf")) {
        std::cerr << "Montserrat font failed to load" << std::endl;
    }

    sf::Font arialFont;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Arial font failed to load" << std::endl;
    }

    // for graduation text
    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    // Calculating Average Score
    int P1score = 0;
    int P2score = 0;
    if (player1.getGPA() > player2.getGPA()) {
        P1score += 1;
    }
    if (player1.getGPA() < player2.getGPA()) {
        P2score += 1;
    }
    if (player1.getDebt() > player2.getDebt()){
        P2score += 1;
    }
    if (player1.getDebt() < player2.getDebt()){
        P1score += 1;
    }
    if (player1.getHappiness() > player2.getHappiness()) {
        P1score += 1;
    }
    if (player1.getHappiness() < player2.getHappiness()) {
        P2score += 1;
    }

    // player one info
    // have to update once resource and player variables have been made
    sf::Text text2;
    text2.setFont(font);
    text2.setString(" Player 1: \n GPA: " + std::to_string(player1.getGPA()) +
                    "\n Student Debt: " + std::to_string(player1.getDebt()) +
                    "\n Happiness: " + std::to_string(player1.getHappiness()) +
                    "\n Winning Categories -/3: " + std::to_string(P1score));
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::White);

    // player two info
    sf::Text text3;
    text3.setFont(font);
    text3.setString(" Player 2: \n GPA: " + std::to_string(player2.getGPA()) +
                    "\n Student Debt: " + std::to_string(player2.getDebt()) +
                    "\n Happiness: " + std::to_string(player2.getHappiness()) +
                    "\n Winning Categories -/3: " + std::to_string(P2score));
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::White);

    sf::Text text4;
    text4.setFont(font);
    text4.setString("Winner is " + Winner(P1score, P2score));
    text4.setCharacterSize(20);
    text4.setFillColor(sf::Color::White);

    // ensures the popup screen is smaller than the main window
    float popupWidth = window.getSize().x * 0.75f;
    float popupHeight = window.getSize().y * 0.9f;

    // position of the center of the pop-up
    float popupX = (window.getSize().x - popupWidth) / 2;
    float popupY = (window.getSize().y - popupHeight) / 2;

    // Place the text on the screen with ideal positioning
    text.setPosition(popupX + 100, popupY + 10);
    text2.setPosition(popupX, popupY + 60);
    text3.setPosition(popupX, popupY + 210);
    text4.setPosition(popupX, popupY + 360);

    // makes the popup screen
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(popupWidth, popupHeight));
    background.setFillColor(sf::Color(91, 10, 125));
    background.setPosition((window.getSize().x - background.getSize().x) / 2, (window.getSize().y - background.getSize().y) / 2);

    sf::Clock timer;
    timer.restart();

    // pop up should be opened for 15 seconds and then will close
    while (timer.getElapsedTime().asSeconds() < 15.0f) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }

        window.draw(background);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.display();
    }
}

/**
 * @brief Determines the winner based on the scores of two players.
 * @param P1score Score of Player 1.
 * @param P2score Score of Player 2.
 * @return A string indicating the winner or a tie.
 */
std::string Graduation::Winner(int P1score, int P2score) {
    if (P1score > P2score) {
        return "Player 1";
    }
    if (P1score < P2score) {
        return "Player 2";
    } else {
        return "Player 1 and Player 2";
    }
}
