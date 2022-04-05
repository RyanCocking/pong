#include "paddle.hpp"

Paddle::Paddle()
    : moveSpeed(2), controlUp(sf::Keyboard::Key::W),
      controlDown(sf::Keyboard::Key::S)
{
    shape.setSize(sf::Vector2f(20, 20));
    shape.setFillColor(sf::Color::Red);
}

Paddle::Paddle(
    float width = 50,
    float height = 50,
    sf::Vector2f initPos = sf::Vector2f(0.0f, 0.0f),
    float speed = 5,
    sf::Keyboard::Key up = sf::Keyboard::Key::W,
    sf::Keyboard::Key down = sf::Keyboard::Key::S)
    : moveSpeed(speed), controlUp(up), controlDown(down)
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

void Paddle::listenForInput()
{
    if (sf::Keyboard::isKeyPressed(controlUp))
    {
        updatePos(0, moveSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(controlDown))
    {
        updatePos(0, -moveSpeed);
    }
}