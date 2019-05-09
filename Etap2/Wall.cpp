#include <ncurses.h>
#include "Wall.h"

Wall::Wall(int initX, int initY){

  
    screenX = initX;
    screenY = initY;
    for(int i = 0; i<80;i++){
        walls.push_back(screenX/2-40+i);
        vectors.push_back(screenX/2-40+i);
    }
    X = screenX/2-40;
    Y = screenY/2+5;

   xVec = 0;
   yVec = 0;
   ballCounter =0;
   
   counter =0;

}

void Wall::drawWall() {
    for(int i =0;i<80;i++){
    move(Y,X+i); 
    printw("-");
    }
 }

 void Wall::releaseBall() {
    this->counter = 0;
    this->ballInsideIndex = -1;
 }

 bool Wall::hasBall() {
     return this->ballInsideIndex > -1;
 }

bool Wall::isBallInWall(Ball *ball) {
    bool tmp = false;
    for(int i = 0; i<80;i++){
        if((this->Y == ball->Y) && (this->walls[i] == ball->X))
        {
            tmp = true;
        }
        
    }
    
    return tmp;

 }

int Wall::areBallsInside(Ball* ball) {
     for(int i = 0; i<80;i++){
        if((this->Y > ball->Y)&&((this->walls[i] == ball->X))){
            counter++;
        }
        
     }
    return counter;

}

 void Wall::increaseCounter() {
     if(this->hasBall())
        this->counter++;
 }

