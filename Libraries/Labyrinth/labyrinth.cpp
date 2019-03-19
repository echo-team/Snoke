#include "labyrinth.h"
/**
 * Set's the starting labyrinth by setting the borders
 * @param {Point} gameFieldSize - dimensions(x, y) of the game field
 */
void Labyrinth::setLabyrinth(Point gameFieldSize)
{
    labyrinth = new char* [gameFieldSize.x];
    for(int i = 0; i < gameFieldSize.x; i++)
    {
        labyrinth[i] = new char [gameFieldSize.y];
        for(int j = 0; j < gameFieldSize.y; j++)
        {
            labyrinth[i][j] = 0;
        }
    }
    for(int i = 0; i < gameFieldSize.x; i++)
    {
        labyrinth[i][0] = '-';
        labyrinth[i][gameFieldSize.y - 1] = '-';
    }
    for(int i = 0; i < gameFieldSize.y; i++)
    {
        labyrinth[0][i] = '|';
        labyrinth[gameFieldSize.x - 1][i] = '|';
    }
}

/**
 * Drawing labyrinth to the console
 * (Should only be used at the start as it is rewriting all the points it includes
 * and not the updated)
 */
void Labyrinth::displayLabyrinth()
{
    for(int i = 0; i < gameFieldSize.x; i++)
    {
        for(int j = 0; j < gameFieldSize.y; j++)
        {
            if(labyrinth[i][j]){
                mvaddch(j, i, labyrinth[i][j]);
            }
        }
    }
}

/**
 * displaying the changed Points
 */
void Labyrinth::displayUpdated(Point* update[2], int size)
{
	Point abc;
    for(int i = 0; i < size; i++)
    {
    	abc = update[1][i];
        mvaddch(abc.y, abc.x, ' ');
        abc = update[0][i];
        mvaddch(abc.y, abc.x, '*');
    }
}

/**
 * Updating the labyrinth(changing the values of some Points)
 * @param {Point*} update    - 2-dimensional array of changes needed to be applied to the labyrinth
 *                 update[0] - an array containing Points to add to the labyrinth
 *                 update[1] - an array containing Points to remove from the labyrinth
 * @param {int}    size      - the longest sequence for updating [max(len(update[0], update[1]))]
 */
void Labyrinth::updateLabyrinth(Point* update[2], int size)
{
    for(int i = 1; i < size; i++)
    {
        Point p = update[0][i];
        if(p.x >= 0 and p.y >= 0)
        {
            labyrinth[p.x][p.y] = 1;
        }
        p = update[1][i];
        if(p.x >= 0 and p.y >= 0)
        {
            labyrinth[p.x][p.y] = 0;
        }
    }
}

bool Labyrinth::isFree(Point p)
{
	return !this->labyrinth[p.x][p.y];
}

bool Labyrinth::addPoint(Point p, char style)
{
	if(this->isFree(p))
	{
		labyrinth[p.x][p.y] = style;
		return true;
	}
	return false;
}

bool Labyrinth::remPoint(Point p)
{
	labyrinth[p.x][p.y] = 0;
	return true;
}

bool Labyrinth::save(std::string name)
{
    FILE* file;
    file = fopen(name, "r");
    if(file)
    {

        return 1;
    }
    return 0;
}