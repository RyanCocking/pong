#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "paddle.hpp"
#include "score.hpp"
#include "constants.hpp"
#include "config.hpp"
#include "ball.hpp"
#include <iostream>
#include <vector>

int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_INIT_WIDTH, WINDOW_INIT_HEIGHT), "Pong");
    window.setFramerateLimit(FRAMES_PER_SEC);
    sf::Clock clock;

    sf::SoundBuffer buf;
    sf::Sound sound;

    buf.loadFromFile(std::string(PROJECT_ASSET_DIR) + "/sounds/4391__noisecollector__pongblipf-5.wav");
    sound = sf::Sound(buf);
    sound.play();

    std::cout << "Hello" << std::endl;

    Ball ball(false);
    Paddle leftPaddle(PADDLE_OFFSET_X,
                      WINDOW_INIT_HEIGHT / 2 - PADDLE_HEIGHT / 2,
                      sf::Keyboard::Key::W, sf::Keyboard::Key::S,
                      std::string(PROJECT_ASSET_DIR) + "/sounds/4390__noisecollector__pongblipf-4.wav");
    Paddle rightPaddle(WINDOW_INIT_WIDTH - PADDLE_OFFSET_X - PADDLE_WIDTH,
                       WINDOW_INIT_HEIGHT / 2 - PADDLE_HEIGHT / 2,
                       sf::Keyboard::Key::Up, sf::Keyboard::Key::Down,
                       std::string(PROJECT_ASSET_DIR) + "/sounds/4391__noisecollector__pongblipf-5.wav");
    std::vector<Paddle> paddles = {leftPaddle, rightPaddle};
    Score leftScore(WINDOW_INIT_WIDTH / 4, 0, WINDOW_INIT_WIDTH);
    Score rightScore(WINDOW_INIT_WIDTH * 3 / 4 - FONT_SIZE_PIXELS, 0, -SCORE_ZONE_WIDTH);

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
            ball.listenForInput();
        }

        ball.paddleCollision(leftPaddle.getShape().getGlobalBounds(), &leftPaddle);
        ball.paddleCollision(rightPaddle.getShape().getGlobalBounds(), &rightPaddle);
        ball.updatePos();

        bool leftHasScored = leftScore.attemptScore(ball.getShape().getGlobalBounds());
        bool rightHasScored = rightScore.attemptScore(ball.getShape().getGlobalBounds());

        if ((leftHasScored == true) and (rightHasScored == true))
        {
            throw std::logic_error("Cannot have simultaneous point scoring");
        }

        ball.resetIfScored(leftHasScored);
        ball.resetIfScored(rightHasScored);

        if ((leftScore.getValue() == SCORE_TO_WIN) or (rightScore.getValue() == SCORE_TO_WIN))
        {
            ball.resetPos();
            leftScore.reset();
            rightScore.reset();
            // sf::sleep()
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
        window.draw(ball.getShape());

        window.draw(leftPaddle.getShape());
        window.draw(rightPaddle.getShape());

        window.draw(leftScore.getText());
        window.draw(rightScore.getText());

        window.draw(centreLine);
        window.display();

        // sf::Time end = clock.getElapsedTime();

        // // The manual way of implementing a FPS limit
        // sf::sleep(start - end + sf::microseconds(MICROSEC_PER_FRAME));
    }

    return 0;
}
