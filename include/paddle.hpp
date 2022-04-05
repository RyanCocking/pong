#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp> // 2D graphics module

class Paddle
{
private:
    sf::RectangleShape shape;
    float moveSpeed;
    sf::Keyboard::Key controlUp;
    sf::Keyboard::Key controlDown;

public:
    Paddle();
    Paddle(float width, float height, sf::Vector2f initPos, float speed,
           sf::Keyboard::Key up, sf::Keyboard::Key down);
    void updatePos(float dx, float dy);
    sf::RectangleShape getShape();
    void listenForInput();
};

#endif