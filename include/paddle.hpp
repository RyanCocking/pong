#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp> // 2D graphics module
#include "constants.hpp"
#include <SFML/Audio.hpp>

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
    sf::SoundBuffer buffer;
    sf::Sound soundOnHit;

public:
    Paddle(float xi, float yi, sf::Keyboard::Key up, sf::Keyboard::Key down,
           std::string soundFile);
    void updatePos(float dx, float dy);
    sf::RectangleShape getShape();
    void listenForInput();
    void checkBounds();
    void playSound();
};
#endif