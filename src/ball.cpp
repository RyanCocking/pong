#include "ball.hpp"

Ball::Ball(bool sides)
    : velocity(sf::Vector2f(BALL_SPEED, BALL_SPEED)),
      controlReset(sf::Keyboard::Key::R),
      enableSideCollision(sides)
{
    shape.setPosition(sf::Vector2f(WINDOW_INIT_WIDTH / 2 - BALL_DIAMETER / 2, WINDOW_INIT_HEIGHT / 2 - BALL_DIAMETER / 2));
    shape.setFillColor(sf::Color::White);
    shape.setSize(sf::Vector2f(BALL_DIAMETER, BALL_DIAMETER));
}

void Ball::wallCollision()
{
    if ((shape.getGlobalBounds().top < 0) or
        (shape.getGlobalBounds().top + shape.getGlobalBounds().height > WINDOW_INIT_HEIGHT))
    {
        velocity.y *= -1;
    }
    else if (enableSideCollision and
             ((shape.getGlobalBounds().left < 0) or
              (shape.getGlobalBounds().left + shape.getGlobalBounds().width > WINDOW_INIT_WIDTH)))
    {
        velocity.x *= -1;
    }
}

void Ball::paddleCollision(sf::FloatRect paddleRect)
{
    if (shape.getGlobalBounds().intersects(paddleRect))
    {
        velocity.x *= -1;
    }

    // needs a situation incase ball hits top of paddle!

    // needs some kind of fake momentum transfer from paddle to ball. based on
    // angle fromc entre of paddle?
}

void Ball::updatePos()
{
    wallCollision();
    shape.move(velocity.x, velocity.y);
}

sf::RectangleShape Ball::getShape()
{
    return shape;
}

void Ball::resetPos()
{
    shape.setPosition(sf::Vector2f(WINDOW_INIT_WIDTH / 2 - BALL_DIAMETER / 2, WINDOW_INIT_HEIGHT / 2 - BALL_DIAMETER / 2));
}

void Ball::listenForInput()
{
    if (sf::Keyboard::isKeyPressed(controlReset))
    {
        resetPos();
    }
}

void Ball::resetIfScored(bool hasScored)
{
    if (hasScored)
    {
        resetPos();
    }
}