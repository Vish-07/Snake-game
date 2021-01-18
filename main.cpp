#include <iostream>
#include <conio.h>
#include <ctime>

#include "Snake.h"
#include "Food.h"

#define WIDTH 50
#define HEIGHT 25
using namespace std;

int score;
Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;

void board()
{
    COORD snake_pos = snake.getPos();
    COORD food_pos = food.get_pos();

    vector<COORD> snakeBody = snake.getBody();
    cout << "Score: " << score << "\n\n\n\n";


    for(int i = 0; i < HEIGHT; ++i)
    {
        cout << "\t\t#";
        for(int j = 0; j < WIDTH - 2; ++j)
        {
            if(i == 0 || i == (HEIGHT - 1))
                cout << "#";

            else if(i == snake_pos.Y && j + 1 == snake_pos.X)
                cout << "0";

            else if(i == food_pos.Y && j + 1  == food_pos.X)
                cout << "*";

            else
            {
                bool bodyPart = false;
                for(int k = 0; k < (snakeBody.size() - 1); k++)
                {
                    if(i == snakeBody[k].Y && j + 1 == snakeBody[k].X)
                    {
                        cout << '0';
                        bodyPart = true;
                        break;
                    }
                }
                if(!bodyPart)
                    cout << ' ';
            }
        }
        cout << "#\n";
    }
}

int main()
{
    score = 0;
    srand(time(NULL));
    food.gen_food();
    bool gameover = false;
    while(!gameover)
    {
        board();

        if(kbhit())
        {
            switch(getch())
            {
            case 72:
                snake.changeDir('w');
                break;
            case 80:
                snake.changeDir('s');
                break;
            case 75:
                snake.changeDir('d');
                break;
            case 77:
                snake.changeDir('a');
                break;
            }

        }


        if(snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow();
            score++;
        }
        if(snake.collided())
            gameover = true;

        snake.moveSnake();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n GAME OVER\n";
    return 0;
}
