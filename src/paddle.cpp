#include "paddle.hpp"

Paddle::Paddle(
    float width = 50,
    float height = 50,
    sf::Vector2f initPos = sf::Vector2(0.0f, 0.0f))
{
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(initPos);
    shape.setFillColor(sf::Color::White);
}

void Paddle::updatePos(float dx, float dy)
{
    shape.move(dx, dy);
}

sf::RectangleShape Paddle::getShape()
{
    return shape;
}