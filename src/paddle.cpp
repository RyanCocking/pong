#include "paddle.hpp"

Paddle::Paddle(
    sf::Keyboard::Key up = sf::Keyboard::Key::W,
    sf::Keyboard::Key down = sf::Keyboard::Key::S)
    : moveSpeed(5),
      shapeWidth(20),
      shapeHeight(100),
      initPos(sf::Vector2f(0.0f, 0.0f)),
      controlUp(up),
      controlDown(down)
{
    shape.setSize(sf::Vector2f(shapeWidth, shapeHeight));
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

void Paddle::listenForInput()
{
    if (sf::Keyboard::isKeyPressed(controlUp))
    {
        updatePos(0, -moveSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(controlDown))
    {
        updatePos(0, moveSpeed);
    }
}