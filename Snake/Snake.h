#ifndef SNAKE_H
#define SNAKE_H

#include<windows.h>
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
	char dir;
	vector <COORD> body;
public:
	Snake(COORD pos, int vel);	//constructor to initialize variables 
	void change_dir(char dir);	//mehod to change direction
	void move_snake();			// method to move snake 
	COORD get_pos();			//get the position of the snake 
	vector<COORD> get_body();
	bool eaten(COORD food);
	void grow();
	bool collided();
	char get_dir(char dir);
};

#endif