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
#include <deque>

/**
 * @class Change change.h
 * @brief   A Support Change class
 * @prop    change  - 2-dim array containing additions and removals for the labyrinth
 */
class Change
{
    private:
        std::deque<Point> change[2];

    public:
        void initChange();
        bool addPoint(Point p);
        bool rmPoint(Point p);
        void wipeChange();
        bool inAddQueue(Point p);
        bool inRmQueue(Point p);
        void getAddQueue(std::deque<Point>* cpChange);
        void getRmQueue(std::deque<Point>* cpChange);
};

#endif
