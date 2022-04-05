#include <SFML/Graphics.hpp>
#include "paddle.hpp"
#include "constants.hpp"
#include <iostream>
#include <vector>

int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_INIT_WIDTH, WINDOW_INIT_HEIGHT), "Pong");
    sf::Clock clock;
    Paddle left(SCORE_ZONE_WIDTH,
                WINDOW_INIT_HEIGHT / 2 - PADDLE_HEIGHT / 2,
                sf::Keyboard::Key::W,
                sf::Keyboard::Key::S);
    Paddle right(WINDOW_INIT_WIDTH - SCORE_ZONE_WIDTH - PADDLE_WIDTH,
                 WINDOW_INIT_HEIGHT / 2 - PADDLE_HEIGHT / 2,
                 sf::Keyboard::Key::Up,
                 sf::Keyboard::Key::Down);

    // The easy way of implementing a FPS limit
    window.setFramerateLimit(FRAMES_PER_SEC);

    while (window.isOpen())
    {

        // sf::Time start = clock.getElapsedTime();

        if (sf::Keyboard::isKeyPressed)
        {
            left.listenForInput();
            right.listenForInput();
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
        window.draw(left.getShape());
        window.draw(right.getShape());
        window.display();

        // sf::Time end = clock.getElapsedTime();

        // // The manual way of implementing a FPS limit
        // sf::sleep(start - end + sf::microseconds(MICROSEC_PER_FRAME));
    }

    return 0;
}
