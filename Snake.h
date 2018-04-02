#pragma once

#ifndef snake_h
#define snake_h
#endif // !snake_h


class Snake
{
public:
	Snake();
	~Snake();

	void start(int x, int y);

	void move(int newX, int newY);

	void addTail(int x, int y);

	int tailX[100], tailY[100];
	
	int nTail;

private:
	
};

