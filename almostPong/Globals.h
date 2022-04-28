#pragma once

#include <Arduboy2.h>
#include "GameState.h"
#include "Ball.h"
#include "Paddle.h"

const uint8_t fps = 45;
const uint8_t LASTLEVEL = 14;
const uint8_t PADDLEWIDTH = 3;

extern Arduboy2 arduboy;

extern GameState gameState;

extern Ball ball;

extern Paddle paddleLeft;

extern Paddle paddleRight;
