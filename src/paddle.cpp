#include "paddle.hpp"

Paddle::Paddle(
    float xi,
    float yi,
    sf::Keyboard::Key up = sf::Keyboard::Key::W,
    sf::Keyboard::Key down = sf::Keyboard::Key::S,
    std::string soundFile = "")
    : moveSpeed(PADDLE_SPEED),
      shapeWidth(PADDLE_WIDTH),
      shapeHeight(PADDLE_HEIGHT),
      initPos(sf::Vector2f(xi, yi)),
      controlUp(up),
      controlDown(down),
      yPosMin(0),
      yPosMax(WINDOW_INIT_HEIGHT - shapeHeight)
{
    shape.setSize(sf::Vector2f(shapeWidth, shapeHeight));
    shape.setPosition(initPos);
    shape.setFillColor(sf::Color::White);

    buffer.loadFromFile(soundFile);
	soundOnHit.setBuffer(buffer);
}

void Paddle::updatePos(float dx, float dy)
{
    checkBounds();
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

void Paddle::checkBounds()
{
    withinMinBound = shape.getGlobalBounds().top >= yPosMin;
    withinMaxBound = shape.getGlobalBounds().top <= yPosMax;

    if (withinMinBound == false)
    {
        shape.setPosition(initPos.x, yPosMin + 1);
    }
    else if (withinMaxBound == false)
    {
        shape.setPosition(initPos.x, yPosMax - 1);
    }
    else if (withinMinBound == false && withinMaxBound == false)
    {
        std::logic_error("Both y bounds exceeded simultaneously");
    }
}

void Paddle::playSound()
{
    
    soundOnHit.play();
}
