#include <condition_variable>

class Ball {
public:
    
    int X, Y; //współrzędne połozenia kulki
    float screenX, screenY;
    int oldXVec, oldYVec; 
    int xVec, yVec; //wspolrzedne wektora przesuniecia
    short direction;  //kierunek w ktorym bedzie poruszax sie kulka
    int speed;  //prędkość poruszania się kulki
    int defaultSpeed; 
    int ballId; 
    std::condition_variable cv;

    
public:
    Ball(short vec, int , int, int, int );
    ~Ball();
    void moveBall();
    void drawBall();
    int getSpeed();
    int getX();
    int getY();
    void clearCircle();
    void setRandomDirection();
    void recover();
    
};
