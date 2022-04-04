#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp> // 2D graphics module

class Paddle
{
private:
    sf::RectangleShape shape;

public:
    Paddle(float width, float height, sf::Vector2f initPos);
    void updatePos(float dx, float dy);
    sf::RectangleShape getShape();
};

#endif