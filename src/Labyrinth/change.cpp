/**
 * @file change.cpp
 * @author Yegor Ignatov
 * @brief realisation of Change class
 * @version 0.1
 * @date 2019-05-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "change.h"


/**
 * @brief   Initializes change array, by resetting it
 */
void Change::initQueue()
{
    this->queue[0] = *(new std::deque<Point>);
    this->queue[1] = *(new std::deque<Point>);
}

/**
 * @brief   adds Point to addition array if it fits the criteria
 * @param   p - Point to add
 * @return    - mark of succesful addition
 */
bool Change::addPoint(Point p)
{
    if(p.x >= 0 && p.y >= 0)
    {
        this->queue[0].push_back(p);
        return true;
    }
    return false;
}

/**
 * @brief   adds Point to removal array if it fits the criteria
 * @param   p - Point to add
 * @return    - mark of succesful addition
 */
bool Change::rmPoint(Point p)
{
    if(p.x >= 0 && p.y >= 0)
    {
        this->queue[1].push_back(p);
        return true;
    }
    return false;
}

/**
 * @brief   Check if Points is in the addition queue
 * @param   p   - point to check
 */
bool Change::inAddQueue(Point p)
{
    for(auto it = queue[0].begin(); it != queue[0].end(); ++it)
    {
        if(*it == p)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief   Check if the Point is in the remove queue
 * @param   p   - point to check
 */
bool Change::inRmQueue(Point p)
{
    for(auto it = queue[1].begin(); it != queue[1].end(); ++it)
    {
        if(*it == p)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief   method to get a copy of addition array
 * @param   cpChange - array, where we copy
 */
void Change::getAddQueue(std::deque<Point>* cpChange)
{
    *cpChange = this->queue[0];
}

/**
 * @brief   method to get a copy of removal array
 * @param   cpChange - array, where we copy
 */
void Change::getRmQueue(std::deque<Point>* cpChange)
{
    *cpChange = this->queue[1];
}
