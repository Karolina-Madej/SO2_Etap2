#include "Screen.h"
#include "Wall.h"
#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <string>
#include <unistd.h>
#include <condition_variable>


using namespace std;

Screen *screen;
Wall* wall;
vector<Ball*> balls;
bool flag = true;
vector<thread> threads;
mutex wallMutex;
mutex updateVec;
int counterBall=0; 
int temp=0;

int mutexCounter=0;
mutex mtx, mtx2;


bool ballCounter(){
int counter=0;
    
     for(int i=0; i<balls.size();i++){
            if(wall->isBallInWall(balls[i])){
        counter++;
        if(counter==3)
        return true;
    }
    }


}


void moveBall(Ball * ball){
 
    while(( flag) ) {
        ball->moveBall();
        usleep(ball->getSpeed());

		//this_thread::sleep_for(std::chrono::milliseconds(50));
         unique_lock<mutex> lck2(mtx2);

        if(wall->isBallInWall(ball)){
            ball->cv.wait(lck2);
        }   
        
        if(ballCounter()){
        for(int i=0; i<balls.size();i++){
            
            balls[i]->cv.notify_all();
            }
        }
        
        lck2.unlock();
    }

}

  
 





void refreshScreen(){

    while(flag) {
        clear();
        wall->drawWall();

        for (int i = 0; i < balls.size(); i++) {
            balls[i]->drawBall();
        }
        refresh();
        usleep(20000);
    }
    clear();
    endwin();
}
void makeWall(){
    float x = screen->getScreenHeight();
    float y = screen->getScreenWidth();

     wall = new Wall(x, y);
     usleep(50000);

}



void newBall(){
    float x = screen->getScreenHeight();
    float y = screen->getScreenWidth();
    short tmp;
    int speed;
    while(flag)
    {

        tmp = rand() % 8 +1;
        speed = 50000;
        Ball *ball = new Ball(tmp,speed, x, y,counterBall);
        balls.push_back(ball);
   
        threads.push_back(thread(moveBall, balls.back()));
        
        usleep(5000000);
        counterBall++;


    }
}
void escape(){
    int inputChar;
    while(flag){
        inputChar = getch();
        if(inputChar == 'q'){
            flag= false;
        }
    }
}

int main() {
    srand(time(NULL));
    screen= new Screen();
    thread generateWall(makeWall);
    thread generateBallThread(newBall);
    thread refreshScreenThread(refreshScreen);
    thread escapeThread(escape);
    
    
    escapeThread.join();
    generateBallThread.join();
    refreshScreenThread.join();
    generateWall.join();

    for(int i = 0; i<threads.size(); i++){
        threads[i].join();
    }
    

    endwin();
    return 0;

}

