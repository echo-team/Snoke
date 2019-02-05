#ifndef GAME_H
#define GAME_H
#include "../Snake/snake.h"
#include <ncurses.h>
#include <iostream>

/**
 * Describes the main game class, which contains all in-game entities and
 * describes the way of their communication
 * @prop   {bool**}  labyrinth    - 2-dimensional array defying current
 *                                  state of every point of the game field
 *                                  (blocked or not)
 * @prop   {int}     speed        - value defying the speed of the game(1 /
 *                                  refresh rate) in milliseconds
 * @prop   {int}     changeSize   - the size of the change sub-arrays
 * @prop   {Snake}   snake        - the local_player controlled snake
 *                                  entity
 * @prop   {Snake*}  snakeEnemies - pointer to an array of the enemy snake
 *                                  entities (presumably controlled over the
 *                                  Web)
 * @prop   {Point**} change       - array that contains changes to be maid
 *                                  to the labyrinth
 */
class Game
{
    private:
        bool** labyrinth;
        int speed;
        int changeSize;
        Snake snake;
        Snake* snakeEnemies;
        Point* change[2];
        void setLabyrinth(Point dimensions);
        void displayLabyrinth();
        void displayUpdated();
        void updateLabyrinth(Point* update[2], int size);
        void setSpeed(int sp);
        bool initSnake(Point begin, int dir, int length);
        bool initChange(Point** change, int size);
    public:
        bool init(int size = 20, int sp = 100);
        int run();
};

#endif
