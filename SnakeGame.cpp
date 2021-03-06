// SnakeGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Snake.h"
#include "Game.h"


Game *g = new Game();

int main(int argc, char* argv[])
{
	
	g->Setup();
	while (!(g->getGameOver())) {
		g->Draw();
		g->Input();
		g->Logic();
	}
    return 0;
}

