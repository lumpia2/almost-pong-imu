#pragma once

#include <Arduboy2.h>

class Paddle
{
public:
  uint8_t x = 0;
  uint8_t y = 0;
  uint8_t vy = 1;
  uint8_t destination = 0;
  uint8_t height = 0;

public:
  void updatePaddle();
  void drawPaddle();
};
