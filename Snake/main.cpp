#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <conio.h>
#include <fstream>
#include "Snake.h"
#include "Food.h"
#define WIDTH 50
#define HEIGHT 25
using namespace std;

Snake snake({ WIDTH/ 2, HEIGHT / 2 }, 1);
Food food;
int score = 0;
int HS = 0;

void board()
{



    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();
    vector <COORD> snake_body = snake.get_body();
    cout << "\t\tScore : " << score << "\n\n";
    cout << "\t\tHigh Score: " << HS << endl;


    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";
        for (int j = 0; j < WIDTH -2; j++)
        {
            if (i == 0 || i == HEIGHT-1) cout << "#";
            else if (i == food_pos.Y && j + 1 == food_pos.X) cout << '@';
            else if (i == snake_pos.Y && j+1 == snake_pos.X) cout << '0';
            else
            {
                bool isBodyPart = false;
                for (int k = 0; k < snake_body.size()-1; k++)
                {
                    if (i == snake_body[k].Y && j + 1 == snake_body[k].X)
                    {
                        cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }
                if (!isBodyPart) cout << ' ';
            }
        }
        cout << "#" << endl;
    }
}
int main()
{

    score = 0;
    ifstream inFile;
    inFile.open("HighScore.txt");
    if (!inFile) exit(1);
    while (inFile >> HS)
    {
        HS = HS;
    }
    inFile.close();
    srand(time(NULL));
    food.gen_food();
    using namespace std::chrono;
    using namespace std::this_thread;
    bool game_over = false;


    while (!game_over)
    {
        board();
        sleep_for(milliseconds(50));
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'w': snake.change_dir('u'); break;
            case 'd': snake.change_dir('r'); break;
            case 's': snake.change_dir('d'); break;
            case 'a': snake.change_dir('l'); break;
            }
        }

        if (snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow();
            score++;
        }
        snake.move_snake();
        if (snake.collided()) game_over = true; 

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
        if (HS <= score)
        {
            fstream inFile;
            inFile.open("HighScore.txt");
            if (!inFile) exit(1);
            HS = score;
            inFile << HS;
            inFile.close();
        }


    }
    return 0;
}
