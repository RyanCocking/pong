#include <SFML/Graphics.hpp>
#include "paddle.hpp"
#include <iostream>

int const FRAMES_PER_SEC = 30;
sf::Int64 const MICROSEC_PER_FRAME = (1.0 / FRAMES_PER_SEC) * 1e6;

int main()
{

    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
    sf::Clock clock;
    Paddle p(sf::Keyboard::Key::W, sf::Keyboard::Key::S);

    // The easy way of implementing a FPS limit
    window.setFramerateLimit(FRAMES_PER_SEC);

    while (window.isOpen())
    {

        // sf::Time start = clock.getElapsedTime();

        if (sf::Keyboard::isKeyPressed)
        {
            p.listenForInput();
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
        window.draw(p.getShape());
        window.display();

        // sf::Time end = clock.getElapsedTime();

        // // The manual way of implementing a FPS limit
        // sf::sleep(start - end + sf::microseconds(MICROSEC_PER_FRAME));
    }

    return 0;
}
