/**
 * @file common.cpp
 * @author Yegor Ignatov
 * @brief shared functions realisation
 * @version 0.1
 * @date 2019-05-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "common.h"

/**
 * @brief   Operation "==" override for the Point class
 * @param   p - the Point to compare with
 * @return    - mark of equality
 * @overload
 */
bool Point::operator== (Point p)
{
    return (this->x == p.x && this->y == p.y);
}

/**
 * @brief   Operation '<<' override for the Point class
 * @param   s - current ostream variable
 * @param   p - a Point to print
 * @overload
 */
std::ostream& operator<< (std::ostream &s, Point p)
{
    s << '(' << p.x << ',' << p.y << ')';
    return s;
}

/**
 * @brief   Cross-platform sleep function cover
 * @param   time - time the game will 'freeze' for in milliseconds
 */
void mSleep(int time)
{
#ifdef _WIN32
    Sleep(time);

#elif defined(_WIN64)
    Sleep(time);
#endif

#ifdef __unix__
    usleep(time*1000);
#endif
}

/**
 * @brief   Check if Points is in the addition queue
 * @param   p          - point to check
 * @param   change     - array of changed Points
 * @param   changeSize - size of the change array
 */
bool inAddChange(Point p, Point* change[2], int changeSize)
{
    for (int i = 0; i < changeSize; i++)
    {
        if(change[0][i] == p)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief   Check if the Point is in the remove queue
 * @param   p          - point to check
 * @param   change     - array of changed Points
 * @param   changeSize - size of the change array
 */
bool inRemChange(Point p, Point* change[2], int changeSize)
{
    for (int i = 0; i < changeSize; i++)
    {
        if(change[1][i] == p)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief   Gets size of current console screen in symdols
 */
Point getConsoleSize()
{
    Point size;
    getmaxyx(stdscr, size.y, size.x);

    return size;
}
