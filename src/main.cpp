#include <SFML/Graphics.hpp>
#include <mathfu/vector.h>
#include <mathfu/glsl_mappings.h> // simplified mathfu Vector definitions
#include <iostream>

int main()
{

    mathfu::Vector<float, 2> v(1.0f, 2.0f);
    mathfu::vec3 x(0, 1, 2);

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

    std::cout << "Hello there!" << v[0] << x[2] << std::endl;

    return 0;
}
