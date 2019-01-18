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
	void setLabyrinth(int size);
	void setSpeed(int sp);
	Snake snake;
	Snake* snakeEnemies;
	int dim = 20;
public:
	bool init(int size = 20, int sp = 100);
	int run();
	void mSleep(int time);
};

#endif
