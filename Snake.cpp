#include "stdafx.h"
#include "Snake.h"


Snake::Snake()
{
}


Snake::~Snake()
{
}

void Snake::start(int x, int y) {
	tailX[0] = x;
	tailY[0] = y;
	nTail = 1;
}

void Snake::move(int newX, int newY) {
	for (int i = nTail - 1; i > 0; i--)
	{
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];
	}
	tailX[0] = newX;
	tailY[0] = newY;
}

void Snake::addTail(int x, int y) {
	for (int i = nTail; i > 0; i--)
	{
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];
	}
	nTail++;
	tailX[0] = x++;
	tailY[0] = y++;

}


