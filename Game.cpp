#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include "Snake.h"

using namespace std;

Game::Game()
{
}


Game::~Game()
{
}


Snake *snake = new Snake();


void Game::sort() {
	srand(int(time(NULL)));
	fruitX = rand() % width;
	fruitY = rand() % height;
	if (fruitX < 1 || fruitX > width - 2 || fruitY < 0 || fruitY > height - 1) {
		sort();
	}
}

void Game::Setup() {

	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	snake->start(x, y);
	sort();
	score = 0;
}

void Game::Draw() {
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
				for (int k = 0; k < snake->nTail; k++)
				{
					if (snake->tailX[k] == j && snake->tailY[k] == i) {
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


}
void Game::Input() {
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

void Game::Logic() {


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


	if (y >= height)
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

	for (int i = 0; i < snake->nTail; i++)
	{
		if (x == snake->tailX[i] && y == snake->tailY[i]) {
			if (dir != STOP) gameOver = true;
		}
	}

	snake->move(x, y);

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		snake->addTail(x, y);
		sort();
	}


}

bool Game::getGameOver() {
	return gameOver;
}

