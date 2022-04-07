#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include "paddle.hpp"
#include <vector>
#include <iostream>

class Ball
{
private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    sf::Keyboard::Key controlReset;
    bool enableSideCollision;

public:
    Ball(bool sides);
    void wallCollision();
    void paddleCollision(sf::FloatRect paddleRect);
    void updatePos();
    sf::RectangleShape getShape();
    void resetPos();
    void listenForInput();
    void resetIfScored(bool hasScored);
};

#endif