#include "common.h"

/**
 * Operation '<<' override for the Point type
 * @param  {std::ostream&} s - current ostream variable
 * @param  {Point}         p - 
 * @return {std::ostream&}
 * @override
 */
std::ostream& operator << (std::ostream &s, Point p)
{
    s << '(' << p.x << ',' << p.y << ')';
    return s;
}

/**
 * Operation '<<' override for the Point type
 * @param  {std::ostream&} s - current ostream variable
 * @param  {Point}         p - 
 * @return {std::ostream&}
 * @override
 */
bool operator == (Point p1, Point p2)
{
    return (p1.x == p2.x and p1.y == p2.y);
}

/**
 * Cross-platform sleep function cover
 * @param {int} time - time the game will 'freeze' for in milliseconds
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
 * Check if Points is in the addition queue
 * @param  {Point}     p       - point to check
 * @param  {Point*[2]} change  - array of changed Points
 * @return {bool}
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
 * Check if the Point is in the removal queue
 *
 * @param  {Point}     p       - point to check
 * @param  {Point*[2]} change  - array of changed Points
 * @return {bool}
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
