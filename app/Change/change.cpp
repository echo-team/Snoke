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
void Change::initChange()
{
    this->change[0] = *(new std::deque<Point>);
    this->change[1] = *(new std::deque<Point>);
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
        this->change[0].push_back(p);
        return true;
    }
    return false;
}

/**
 * @brief   adds Point to removal array if it fits the criteria
 * @param   p - Point to add
 * @return    - mark of succesful addition
 */
bool Change::remPoint(Point p)
{
    if(p.x >= 0 && p.y >= 0)
    {
        this->change[1].push_back(p);
        return true;
    }
    return false;
}

/**
 * @brief   Check if Points is in the addition queue
 * @param   p   - point to check
 */
bool Change::inAddChange(Point p)
{
    for(auto it = change[0].begin(); it != change[0].end(); ++it)
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
bool Change::inRemChange(Point p)
{
    for(auto it = change[1].begin(); it != change[1].end(); ++it)
    {
        if(*it == p)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief method to get a copy of addition array
 * @param   cpChange - array, where we copy
 */
void Change::getAddChange(std::deque<Point>* cpChange)
{
    cpChange->assign(this->change[0].begin(), this->change[0].end());
}

/**
 * @brief method to get a copy of removal array
 * @param   cpChange - array, where we copy
 */
void Change::getRemChange(std::deque<Point>* cpChange)
{
    cpChange->assign(this->change[1].begin(), this->change[1].end());
}
