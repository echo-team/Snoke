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
#include "../Labyrinth/change.h"
#include <ncurses.h>
#include <iostream>
#include <string>
#include <time.h>
#include <signal.h>

/**
 * @class Game game.h
 * @brief   Main game class
 * @prop    speed           - game refresh rate(in milliseconds)
 * @prop    snake           - the local player controlled snake
 * @prop    snakeEnemies    - the remotely controlled snake entities
 * @prop    labyrinth       - object containing labyrinth, displaying it, etc
 */
class Game
{
    private:
        int speed;
        int loops;
        Snake snake;
        Snake* snakeEnemies;
        Labyrinth labyrinth;
        void setSpeed(int sp);
        void setLoops(int loops);
        bool initSnake(Point begin, short dir, int length);
    public:
        bool init(int size = 20, int sp = 100, int loops = -1);
        int run();
};

#endif
