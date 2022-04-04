#include <SFML/Graphics.hpp>
#include "paddle.hpp"

int main()
{

    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
    Paddle p(50, 200, sf::Vector2f(0, 20));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(p.getShape());
        window.display();
    }

    return 0;
}
