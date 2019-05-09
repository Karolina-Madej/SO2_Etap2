#include <ncurses.h>
#include "Ball.h"

Ball::Ball(short direction, int defaultSpeed, int initX, int initY,  int ballId) {
    this->direction = direction;
    this->speed = defaultSpeed;
    this->defaultSpeed=defaultSpeed;
    this->ballId=ballId;
    

    screenX = initX;
    screenY = initY;

    X = screenX/2;
    Y = screenY/2;
    setRandomDirection();
}

void Ball::moveBall() {
   
    X += xVec;
    Y += yVec;
    speed+=3000;

    if( X >= screenX ) {
      
        xVec *= -1;
        speed=defaultSpeed;             
        
    }

    if(X<=0){
        xVec *= -1;
        speed=defaultSpeed; 
       
    }

    if( Y >= screenY  ) {
        yVec *= -1;
        speed=defaultSpeed; 
       
          
       
    }

    if(Y <= 0){
        yVec *= -1;
        speed=defaultSpeed; 
        
    }
}


void Ball::drawBall() {
    move(Y,X);
    printw("o");
}

int Ball::getSpeed() {
    return this->speed;
}

void Ball::setRandomDirection() {
       
         switch (direction) {
        case 1:
            xVec = 0;
            yVec = 1;
            break;
        case 2:
            xVec = 1;
            yVec = 1;
            break;
        case 3:
            xVec = 1;
            yVec = 0;
            break;
        case 4:
            xVec = 1;
            yVec = -1;
            break;
        case 5:
            xVec = 0;
            yVec = -1;
            break;
        case 6:
            xVec = -1;
            yVec = -1;
            break;
        case 7:
            xVec = -1;
            yVec = 0;
            break;
        case 8:
            xVec = -1;
            yVec = 1;
            break;
        default:
            xVec = 1;
            yVec = 1;
            break;
    }
    
        
    
}
void Ball::recover(){
    this->xVec=oldXVec;
    this->yVec=oldYVec;
    this->moveBall();
}

int Ball::getX()
{
    return this->X;
}

int Ball::getY()
{
    return this->Y;
}
