#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp> // 2D graphics module
#include "constants.hpp"

class Paddle
{
private:
    sf::RectangleShape shape;
    float moveSpeed;
    int shapeWidth;
    int shapeHeight;
    sf::Vector2f initPos;
    sf::Keyboard::Key controlUp;
    sf::Keyboard::Key controlDown;
    int yPosMin;
    int yPosMax;
    bool withinMinBound;
    bool withinMaxBound;

public:
    Paddle(float x0, float y0, sf::Keyboard::Key up, sf::Keyboard::Key down);
    void updatePos(float dx, float dy);
    sf::RectangleShape getShape();
    void listenForInput();
    void checkBounds();
};

#endif