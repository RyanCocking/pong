#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "config.hpp"
#include "constants.hpp"

class Score
{
private:
    std::string filePath;
    sf::Font font;
    sf::Text text;
    int scoreVal;
    int scoreZoneX;
    sf::RectangleShape scoreZone;

public:
    Score(float textX, float textY, float zoneX);
    void updateText();
    void increase();
    void reset();
    sf::Text getText();
    int getValue();
    bool attemptScore(sf::FloatRect rectBounds);
    sf::RectangleShape getScoreZone();
};

#endif