#include "Ball.h"
#include "Globals.h"

#include <Arduboy2.h>

void Ball::updateBall(){
  this->x+=vx;
  this->y+=vy;

  if(arduboy.everyXFrames(2)){
    this->vy+=this->g;
  }

  
  if(arduboy.everyXFrames(50)){
    this->vx*=1.04;
  }
  
  if(this->x>120){
    if(this->y+3 > paddleRight.y and this->y < paddleRight.y+18){
      this->vx = -abs(this->vx);
      paddleRight.destination = random(3,45);
      gameState=GameState::AddPoints;
    }else{
      gameState=GameState::EndGame;
    }
  }
  if(this->x<6){
    if(this->y+3 > paddleLeft.y and this->y < paddleLeft.y+18){
      this->vx = abs(this->vx);
      paddleLeft.destination = random(3,45);
      gameState=GameState::AddPoints;
    }else{
      gameState=GameState::EndGame;
    }
  }
  if(this->y>66 and this->y<250){
    gameState=GameState::EndGame;
  }
  
}

void Ball::drawBall(){
  arduboy.drawRect(this->x,this->y , r,r, WHITE);
    arduboy.setCursor(60, 27);
}


void Ball::processInputs(){
  if(arduboy.justPressed(UP_BUTTON) or arduboy.justPressed(A_BUTTON)){
      this->vy = -2.5;
    }
}

void Ball::resetBall(){
  this->x = 10;
  this->y = 20;
  this->vx = 1;
  this->vy = 0;
}
