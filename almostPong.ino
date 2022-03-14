#include <Arduboy2.h>
#include "Globals.h"

int score=0;
int highScore=0;

const uint8_t PROGMEM title[] = {
0x3e, 0x09, 0x09, 0x3f, 0x3f, 0x3e, 0x00, 0x00, 0x3f, 0x3f, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x3f, 0x06, 0x0c, 0x06, 0x3f, 0x3f, 0x00, 0x00, 0x1e, 0x3f, 0x21, 0x21, 0x3f, 0x1e, 0x00, 0x00, 0x12, 0x27, 0x25, 0x3d, 0x3d, 0x18, 0x00, 0x00, 0x01, 0x01, 0x3f, 0x3f, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x09, 0x09, 0x0f, 0x06, 0x00, 0x00, 0x1e, 0x3f, 0x21, 0x21, 0x3f, 0x1e, 0x00, 0x00, 0x3f, 0x06, 0x0c, 0x18, 0x3f, 0x3f, 0x00, 0x00, 0x1e, 0x3f, 0x21, 0x29, 0x3b, 0x3a, 
};

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(fps);
  arduboy.clear();
  paddleLeft.x = 5;
  paddleRight.x = 123;
  paddleLeft.y = 55;
  paddleRight.y = 45;
}

void loop() {
  if (!(arduboy.nextFrame())){
    return;
  }
  
  arduboy.clear();
  arduboy.pollButtons();
  
  if (gameState==GameState::MainMenu){
    titleScreen();
    if(arduboy.justPressed(A_BUTTON)){
      gameState=GameState::Game;
      ball.resetBall();
      arduboy.clear();
    }
  }
  if (gameState==GameState::AddPoints){
    score++;
    gameState=GameState::Game;
  }
  if (gameState==GameState::Game){
    arduboy.setCursor(60, 30);
    arduboy.print(score);
    paddleLeft.updatePaddle();
    paddleLeft.drawPaddle();
    paddleRight.updatePaddle();
    paddleRight.drawPaddle();
    ball.processInputs();
    ball.updateBall();
    ball.drawBall();
  }
  if (gameState==GameState::EndGame){
      arduboy.clear();
      paddleRight.y = random(3,45);
      paddleRight.y = random(3,45);
      if(score > highScore){
        highScore = score;
        arduboy.setCursor(10, 0);
        arduboy.setTextSize(1);
        arduboy.print("New Record!");
      }
      score = 0;
    endScreen();
    arduboy.delayShort(3000);
    gameState=GameState::MainMenu;
  }

  arduboy.display();
}





void titleScreen(){

  arduboy.drawBitmap(20,15,title,82,6);
  
  arduboy.setTextSize(1);
  arduboy.setCursor(42, 45);
  arduboy.print("Press A");
  arduboy.setCursor(20, 55);
  arduboy.print("High Score: ");
  arduboy.print(highScore);
  arduboy.display();
}

void endScreen(){
  arduboy.setCursor(35, 15);
  arduboy.setTextSize(1);
  arduboy.print("Game Over");
  arduboy.display();
}
