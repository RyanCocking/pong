#include <SFML/Graphics.hpp>
#include "paddle.hpp"
#include "score.hpp"
#include "constants.hpp"
#include "config.hpp"
#include <iostream>
#include <vector>

int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_INIT_WIDTH, WINDOW_INIT_HEIGHT), "Pong");
    window.setFramerateLimit(FRAMES_PER_SEC);
    sf::Clock clock;

    Paddle leftPaddle(PADDLE_OFFSET_X,
                      WINDOW_INIT_HEIGHT / 2 - PADDLE_HEIGHT / 2,
                      sf::Keyboard::Key::W,
                      sf::Keyboard::Key::S);
    Paddle rightPaddle(WINDOW_INIT_WIDTH - PADDLE_OFFSET_X - PADDLE_WIDTH,
                       WINDOW_INIT_HEIGHT / 2 - PADDLE_HEIGHT / 2,
                       sf::Keyboard::Key::Up,
                       sf::Keyboard::Key::Down);
    Score leftScore(WINDOW_INIT_WIDTH / 4, 0, -SCORE_ZONE_WIDTH);
    Score rightScore(WINDOW_INIT_WIDTH * 3 / 4 - FONT_SIZE_PIXELS, 0, WINDOW_INIT_WIDTH);

    sf::RectangleShape centreLine;
    centreLine.setFillColor(sf::Color::White);
    centreLine.setPosition(WINDOW_INIT_WIDTH / 2, 0);
    centreLine.setSize(sf::Vector2f(1, WINDOW_INIT_HEIGHT));

    while (window.isOpen())
    {

        // sf::Time start = clock.getElapsedTime();

        if (sf::Keyboard::isKeyPressed)
        {
            leftPaddle.listenForInput();
            rightPaddle.listenForInput();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(leftPaddle.getShape());
        window.draw(rightPaddle.getShape());

        window.draw(leftScore.getText());
        window.draw(rightScore.getText());

        window.draw(leftScore.getScoreZone());
        window.draw(rightScore.getScoreZone());

        window.draw(centreLine);
        window.display();

        // sf::Time end = clock.getElapsedTime();

        // // The manual way of implementing a FPS limit
        // sf::sleep(start - end + sf::microseconds(MICROSEC_PER_FRAME));
    }

    return 0;
}
