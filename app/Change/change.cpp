#include "change.h"
/**
 * @brief Initializes change array, containing Points to be changed in the labyrinth
 */
void Change::initChange()
{
    this->changeSize = 2;
    this->change[0] = new Point [changeSize];
    this->change[1] = new Point [changeSize];
}


/**
 * @brief   Initialization of the change array
 * @param   lChange - The pointer to an array
 * @param   size   - The size of array(number of elements it can contain)
 */
bool Change::wipeChange()
{
    Point emptyPoint;
    emptyPoint.x = -1;
    emptyPoint.y = -1;
    emptyPoint.style.bg = 0;
    emptyPoint.style.fg = 0;
    emptyPoint.style.letter = 0;
    for(int i = 0; i < this->changeSize; i++)
    {
        this->change[0][i] = emptyPoint;
        this->change[1][i] = emptyPoint;
    }
    return true;
}

int Change::getSize()
{
    return this->changeSize;
}
