#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

int const WINDOW_INIT_WIDTH = 1200;
int const WINDOW_INIT_HEIGHT = 800;
int const FRAMES_PER_SEC = 30;
sf::Int64 const MICROSEC_PER_FRAME = (1.0 / FRAMES_PER_SEC) * 1e6;

int const PADDLE_OFFSET_X = 100;
float const PADDLE_SPEED = 30.0f;
int const PADDLE_WIDTH = 20;
int const PADDLE_HEIGHT = 160;
int const BALL_DIAMETER = 20;
int const BALL_SPEED = 15;

int const SCORE_ZONE_WIDTH = 200;
int const SCORE_ZONE_HEIGHT = 2 * WINDOW_INIT_HEIGHT;

int const FONT_SIZE_PIXELS = 72;

int const SCORE_TO_WIN = 11;

std::string const PROJECT_ASSET_DIR = "assets";

#endif
