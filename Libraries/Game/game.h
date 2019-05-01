#ifndef GAME_H
#define GAME_H
#include "../Snake/snake.h"
#include "../Labyrinth/labyrinth.h"
#include <ncurses.h>
#include <iostream>
#include <string>
#include <signal.h>

/**
 * @class Main game class
 * @prop {int} speed - game refresh spee(in milliseconds)
 * @prop {int} changeSize - the size of the change sub-arrays
 * @prop {Snake} snake - the local_player-controlled snake entity
 * @prop {Snake*} snakeEnemies - the remotely controlled snake entities
 * @prop {Labyrinth} labyrinth - object containing labyrinth, displaying it, etc
 * @prop {Point*} change - 2-dim array containing changes for the labyrinth
 */
class Game
{
    private:
        int speed;
        int changeSize;
        Snake snake;
        Snake* snakeEnemies;
        Labyrinth labyrinth;
        Point* change[2];
        void setSpeed(int sp);
        bool initSnake(Point begin, int dir, int length);
        bool initBall(Ball* ball);
        bool wipeChange(Point** change, int size);
    public:
        bool init(int size = 20, int sp = 100);
        int run();
};

#endif
