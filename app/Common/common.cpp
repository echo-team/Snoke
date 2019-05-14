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

#ifdef __unix__
#pragma pack(push,1)
struct timespec req;
#pragma pack(pop)
#pragma pack(push,1)
struct timespec rem;
#pragma pack(pop)
#endif

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
    req.tv_sec = time / 1000;
    req.tv_nsec = (time % 1000) * 1000000;
    nanosleep(&req, &rem);
#endif
}

/**
 * @brief   setting new values for sleep function on signal interrupt
 */
void sleepHandler()
{
#ifdef __unix__
    req = rem;
    rem.tv_sec = 0;
    rem.tv_nsec = 0;
#endif
}

/**
 * @brief   For unix-based systems interrupted sleep must be continued
 */
void addSleep()
{
#ifdef __unix__
    nanosleep(&req, &rem);
#endif
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
