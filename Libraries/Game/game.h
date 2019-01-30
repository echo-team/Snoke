#ifndef GAME_H
#define GAME_H
#include "../Snake/snake.h"
#include <ncurses.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>


class Game
{
private:
	bool** labyrinth;
	int speed;
	void setLabyrinth(Point dim);
	void displayLabyrinth();
	void updateLabyrinth(Point update[], int size);
	void setSpeed(int sp);
	Snake snake;
	Snake* snakeEnemies;
	Point dim;
public:
	bool init(int size = 20, int sp = 100);
	int run();
	void mSleep(int time);
};

#endif
