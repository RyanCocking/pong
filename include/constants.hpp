#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

int const WINDOW_INIT_WIDTH = 300;
int const WINDOW_INIT_HEIGHT = 300;
int const FRAMES_PER_SEC = 30;
sf::Int64 const MICROSEC_PER_FRAME = (1.0 / FRAMES_PER_SEC) * 1e6;

int const SCORE_ZONE_WIDTH = 50;
float const PADDLE_SPEED = 5.0f;
int const PADDLE_WIDTH = 20;
int const PADDLE_HEIGHT = 100;

#endif