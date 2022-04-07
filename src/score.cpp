#include "score.hpp"

Score::Score(float textX, float textY, float zoneX)
    : filePath(std::string(PROJECT_ASSET_DIR) + std::string("/fonts/DejaVuSansMono.ttf")),
      scoreVal(0)
{
    font.loadFromFile(filePath);
    text.setFont(font);
    text.setString(std::to_string(scoreVal));
    text.setCharacterSize(FONT_SIZE_PIXELS);
    text.setFillColor(sf::Color::White);
    text.setPosition(textX, textY);

    scoreZone.setSize(sf::Vector2f(SCORE_ZONE_WIDTH, SCORE_ZONE_HEIGHT));
    scoreZone.setPosition(zoneX, WINDOW_INIT_HEIGHT / 2 - scoreZone.getSize().y / 2);
    scoreZone.setFillColor(sf::Color::Red);
}

void Score::updateText()
{
    text.setString(std::to_string(scoreVal));
}

void Score::increase()
{
    scoreVal++;
    updateText();
}

void Score::reset()
{
    scoreVal = 0;
    updateText();
}

sf::Text Score::getText()
{
    return text;
}

int Score::getValue()
{
    return scoreVal;
}

bool Score::attemptScore(sf::FloatRect rectBounds)
{
    if (scoreZone.getGlobalBounds().intersects(rectBounds))
    {
        increase();
        return true;
    }
    return false;
}

sf::RectangleShape Score::getScoreZone()
{
    return scoreZone;
}