#include "Paddle.h"
#include "Globals.h"

#include <Arduboy2.h>

void Paddle::updatePaddle(){
  if(this->y <  this->destination){
    this->y += vy;
  }
  if(this->y >  this->destination){
    this->y -= vy;
  }
}

void Paddle::drawPaddle(){
  arduboy.drawRect(this->x,this->y, 2, 18, WHITE);
}
