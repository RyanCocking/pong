#include <SFML/Graphics.hpp>
// include <mathfu/vector.h>
#include <iostream>

int main()
{
    //   mathfu::Vector<float, 2> v(1.0f, 2.0f);

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    std::cout << "Hello there!" << std::endl;

    return 0;
}
