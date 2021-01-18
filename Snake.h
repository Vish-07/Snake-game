#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

class Snake
{
    private:
        COORD pos;
        int len;
        int vel;
        char direction;
        vector<COORD> body;

    public:
        Snake(COORD pos, int vel);
        void changeDir(char dir);
        void moveSnake();
        COORD getPos();
        bool eaten(COORD pos);
        void grow();
        bool collided();
        vector<COORD> getBody();
};

#endif // SNAKE_H
