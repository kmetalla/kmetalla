#ifndef FOOD_H
#define FOOD_H
#include <windows.h>
#include <cstdlib>

#define WIDTH 50
#define HEIGHT 25
class Food
{
private:
	COORD pos;
public:
	void gen_food();
	COORD get_pos();
};
#endif
