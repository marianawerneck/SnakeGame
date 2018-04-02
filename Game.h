#pragma once

#ifndef game
#define game
#endif // !game_h


class Game
{
public:
	Game();
	~Game();

	void sort();

	void Setup();

	void Draw();

	void Input();

	void Logic();

	bool getGameOver();

private:
	bool gameOver;
	const int width = 40;
	const int height = 20;
	int x, y, fruitX, fruitY, score;
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection prevDir;
	eDirection dir;
	
};

