#ifndef GAME_H
#define GAME_H
#include "snake.h"
#include <ncurses.h>
class Game
{
private:
	bool** labyrinth;
	Snake snake;
	void setLabyrinth(int size);
	void setSpeed();
	Snake snakeEnemies[3];
public:
	int init();
	int run();
};
#endif