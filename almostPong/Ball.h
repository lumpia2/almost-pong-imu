#pragma once

#include <Arduboy2.h>

class Ball
{
public:
  float x = 10;
  float y = 20;
  float r = 3;
  float vx = 1;
  float vy = 0;
  float g = 0.3;

public:
  void resetBall();
  void updateBall();
  void drawBall();
  void processInputs(float);
};
