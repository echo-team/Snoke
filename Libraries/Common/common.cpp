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
 * @brief   Operation "=" override for the PointStyle type
 * @param   ps - the obgect, parameters of which are being copied
 * @return     - a pointer to an object
 * @overload
 */
PointStyle& PointStyle::operator = (PointStyle ps)
{
    this->letter = ps.letter;
    this->fg = ps.fg;
    this->bg = ps.bg;
    return *this;
}

/**
 * @brief   Operation "=" override for the Point type
 * @param   p - the obgect, parameters of which are being copied
 * @return    - a pointer to an object
 * @overload
 */
Point& Point::operator = (Point p)
{
    this->x = p.x;
    this->y = p.y;
    this->style = p.style;
    return *this;
}

/**
 * @brief   Operation "==" override for the Point type
 * @param   p1 - The first Point
 * @param   p2 - The second Point
 * @return     - mark of equality
 * @overload
 */
bool operator == (Point p1, Point p2)
{
    return (p1.x == p2.x and p1.y == p2.y);
}

/**
 * @brief   Operation '<<' override for the Point type
 * @param   s - current ostream variable
 * @param   p - a Point to print
 * @overload
 */
std::ostream& operator << (std::ostream &s, Point p)
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
