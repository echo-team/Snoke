/*!
   \file game.h
   \brief Definitions and prototypes for Game class
   \author Egor Ignatov
   \date 03/05/2019
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
 */
class Game
{
    private:
        /**
        * @prop    int          speed
        * @brief   game refresh rate(in milliseconds)
        */
        int speed;
        /**
        * @prop    int          changeSize
        * @brief   the size of the change sub-arrays
        */
        int changeSize;
        /**
        * @prop    Snake        snake
        * @brief   the local_player-controlled snake entity
        */
        Snake snake;
        /**
         * @prop    Snake*      snakeEnemies
         * @brief   the remotely controlled snake entities
         */
        Snake* snakeEnemies;
        /**
         * @prop    Labyrinth   labyrinth
         * @brief   object containing labyrinth, displaying it, etc
         */
        Labyrinth labyrinth;
        /**
         * @prop    Point*      change
         * @brief   2-dim array containing changes for the labyrinth
         */
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
