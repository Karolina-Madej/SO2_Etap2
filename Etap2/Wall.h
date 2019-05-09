#include "Ball.h"
#include <vector>

class Wall {

public:
        int X, Y; // pozycja kreski
        int xVec, yVec; 
        float screenX, screenY;
        int counter;
        int ballCounter;
        int ballInsideIndex=-1;
        std::vector<int> walls;
        std::vector<int> vectors;
    


public:
        Wall (int, int);
        void drawWall();
        int getX();
        int getY();
        void releaseBall();
        bool hasBall();
        bool isBallInWall(Ball*);
        int areBallsInside(Ball*);

        void increaseCounter();
};