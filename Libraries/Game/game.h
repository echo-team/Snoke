/**
 * @file game.h
 * @author Yegor Ignatov
 * @brief Definitions and prototypes for Game class
 * @version 0.1
 * @date 2019-05-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef GAME_H
#define GAME_H
#include "../Snake/snake.h"
#include "../Labyrinth/labyrinth.h"
#include <ncurses.h>
#include <iostream>
#include <string>
#include <signal.h>

/**
 * @class Game game.h
 * @brief   Main game class
 * @prop    speed           - game refresh rate(in milliseconds)
 * @prop    changeSize      - the size of the change sub-arrays
 * @prop    snake           - the local_player controlled snake
 * @prop    snakeEnemies    - the remotely controlled snake entities
 * @prop    labyrinth       - object containing labyrinth, displaying it, etc
 * @prop    change          - 2-dim array containing changes for the labyrinth
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
        bool wipeChange(Point** lChange, int size);
    public:
        bool init(int size = 20, int sp = 100);
        int run();
};

#endif
