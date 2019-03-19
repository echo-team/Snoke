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
            labyrinth[i][j] = ' ';
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

void Labyrinth::addSnake(std::list<Point> snake)
{
    for(auto it = snake.begin(); it != snake.end(); ++it)
    {
        addPoint(*it);
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
            mvaddch(j, i, labyrinth[i][j]);
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
        mvaddch(abc.y, abc.x, abc.style.letter);
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
    Point p;
    for(int i = 0; i < size; i++)
    {
        p = update[0][i];
        if(p.x >= 0 and p.y >= 0)
        {
            addPoint(p);
        }
        p = update[1][i];
        if(p.x >= 0 and p.y >= 0)
        {
            remPoint(p);
        }
    }
}

bool Labyrinth::isFree(Point p)
{
    return (this->labyrinth[p.x][p.y] == ' ');
}

bool Labyrinth::addPoint(Point p)
{
	if(this->isFree(p))
	{
        labyrinth[p.x][p.y] = p.style.letter;
		return true;
	}
	return false;
}

bool Labyrinth::remPoint(Point p)
{
    labyrinth[p.x][p.y] = ' ';
	return true;
}

bool Labyrinth::save(char name[MAXLINE])
{
    FILE* file;
    char strout[MAXLINE];
    file = fopen(name, "w");
    if(file)
    {
        fprintf(file, "%d %d\n", gameFieldSize.x, gameFieldSize.y);

        //Printing the game field excluding the borders
        for(int j = 1; j < gameFieldSize.y - 1; j++)
        {
            for(int i = 1; i < gameFieldSize.x - 1; i++)
            {
                fprintf(file, "%c", labyrinth[i][j]);
            }
            fprintf(file, "\n");
        }
        sprintf(strout, "Succesfully saved to %s", name);
        mvaddstr(gameFieldSize.y / 2, 5, strout);
        return 1;
    }
    sprintf(strout, "Couldn't save to %s", name);
    mvaddstr(gameFieldSize.y / 2, 5, strout);
    return 0;
}
