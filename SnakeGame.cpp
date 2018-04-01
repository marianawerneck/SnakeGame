// SnakeGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection prevDir;
eDirection dir;

void sort() {
	srand(time(NULL));
	fruitX = rand() % width;
	fruitY = rand() % height;
	if (fruitX < 1 || fruitX > width - 2 || fruitY < 0 || fruitY > height - 1) {
		sort();
	}
}

void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	tailX[0] = x;
	tailY[0] = y;
	nTail = 1;
	sort();
	score = 0;
}

void Draw() {
	system("cls"); // system("clear");
	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0) cout << "#";
			else if (i == y && j == x) cout << "O";
			else if (i == fruitY && j == fruitX) cout << "$";
			else if (j == width - 1) cout << "#";
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					
					if (tailX[k] == j && tailY[k] == i) {
						if (!print) {
							cout << "X";
							print = true;
						}
						
					}
					
					
				}
				if (!print) {
					cout << " ";
				}
				
				
				
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score << endl;
	for (int i = 0; i < nTail; i++)
	{
		cout << tailX[i]<< "|" << tailY[i] << ";";
	}

}
void Input() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (dir != RIGHT) {
				dir = LEFT;
			}
			break;
		case 'd':
			if (dir != LEFT)
			{
				dir = RIGHT;
			}
			break;
		case 'w':
			if (dir != DOWN)
			{
				dir = UP;
			}
			break;
		case 's':
			if (dir != UP)
			{
				dir = DOWN;
			}
			break;
		case 'l':
			gameOver = true;
			break;
		default:
			break;
		}
	}
}

void move(int newX, int newY) {
	for (int i = nTail - 1; i > 0; i--)
	{
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];
	}
	tailX[0] = newX;
	tailY[0] = newY;
}


void addTail(int x, int y) {
	for (int i = nTail; i > 0; i--)
	{
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];
	}
	nTail++;
	tailX[0] = x++;
	tailY[0] = y++;
	
}

void Logic() {

//	int prevX = tailX[0];
//	int prevY = tailY[0];
//	int prev2X, prev2Y;
//	for (int i = 1; i < nTail; i++)
//	{
//		prev2X = tailX[i];
//		prev2Y = tailY[i];
//		tailX[i] = prevX;
//		tailY[i] = prevY;
//		prevX = prev2X;
//		prevY = prev2Y;
//	}

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}


	if ( y >= height)
	{
		y = 0;
	}
	else {
		if (y < 0) {
			y = height - 1;
		}
	}

	if (x >= width - 1) {
		x = 1;
	}
	else {
		if (x <= 0) {
			x = width - 1;
		}
	}

	for (int i = 0; i < nTail; i++)
	{
		if (x == tailX[i] && y == tailY[i]) {
			if(dir != STOP) gameOver = true;
		}
	}

	move(x, y);

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		addTail(x, y);
		fruitX = rand() % width;
		fruitY = rand() % height;
	}

	
}

int main()
{
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
	}
    return 0;
}

