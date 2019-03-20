#ifndef GAME_H
#define GAME_H
#include "../Snake/snake.h"
#include "../Labyrinth/labyrinth.h"
#include <curses.h>
#include <iostream>
#include <string>

/**
 * @class Main game class
 * @prop {bool**}  labyrinth    - 2-dimensional array defying the game field
 * @prop {int}     speed        - game speed (in milliseconds)
 * @prop {int}     changeSize   - the size of the change sub-arrays
 * @prop {Snake}   snake        - the local_player controlled snake
 * @prop {Snake*}  snakeEnemies - the enemy snakes (contolled by other players)
 * @prop {Point**} change       - array that contains changes for the labyrinth
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
