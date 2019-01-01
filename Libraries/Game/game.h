class Game
{
private:
	int** labyrinth;
	Snake snake;
	Snake snakeEnemies[];
	void setLabyrinth();
	void setSpeed();
	
public:
	int init();
	int run();
};

#include "game.cpp"