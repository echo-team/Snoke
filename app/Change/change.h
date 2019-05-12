/**
 * @file change.h
 * @author Yegor Ignatov
 * @brief Definitions and prototypes for Change class
 * @version 0.1
 * @date 2019-05-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef CHANGE_H
#define CHANGE_H
#include "../Common/common.h"

/**
 * @class Game game.h
 * @brief   A Support Change class
 * @prop    changeSize      - the size of the change sub-arrays
 * @prop    change          - 2-dim array containing changes for the labyrinth
 */
class Game
{
    private:
        int changeSize;
        Point* change[2];

    public:
        void initChange();
        bool wipeChange(Point** lChange, int size);
        int getSize();
};

#endif
