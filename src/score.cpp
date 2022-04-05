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

bool Score::withinScoreZone(sf::Vector2f vec)
{
    float x0 = scoreZone.getGlobalBounds().left;
    float x1 = x0 + scoreZone.getGlobalBounds().width;
    float y0 = scoreZone.getGlobalBounds().top;
    float y1 = y0 + scoreZone.getGlobalBounds().height;
    if ((vec.x > x0 and vec.x < x1) and (vec.y > y0 and vec.y < y1))
    {
        return true;
    }
    return false;
}

sf::RectangleShape Score::getScoreZone()
{
    return scoreZone;
}