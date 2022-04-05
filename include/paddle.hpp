#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp> // 2D graphics module

class Paddle
{
private:
    sf::RectangleShape shape;
    float moveSpeed;
    float shapeWidth;
    float shapeHeight;
    sf::Vector2f initPos;
    sf::Keyboard::Key controlUp;
    sf::Keyboard::Key controlDown;

public:
    Paddle();
    Paddle(sf::Keyboard::Key up, sf::Keyboard::Key down);
    void updatePos(float dx, float dy);
    sf::RectangleShape getShape();
    void listenForInput();
};

#endif