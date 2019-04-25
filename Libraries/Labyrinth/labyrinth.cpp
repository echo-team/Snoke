#include "labyrinth.h"
/**
 * Set's the starting labyrinth by setting the borders
 * @param {Point} gameFieldSize - dimensions(x, y) of the game field
 */
void Labyrinth::setLabyrinth(Point gameFieldSize)
{
    labyrinth = new char* [gameFieldSize.y];
    for(int i = 0; i < gameFieldSize.y; i++)
    {
        labyrinth[i] = new char [gameFieldSize.x];
        for(int j = 0; j < gameFieldSize.x; j++)
        {
            labyrinth[i][j] = ' ';
        }
    }
    for(int i = 0; i < gameFieldSize.x; i++)
    {
        labyrinth[0][i] = '-';
        labyrinth[gameFieldSize.y - 1][i] = '-';
    }
    for(int i = 0; i < gameFieldSize.y; i++)
    {
        labyrinth[i][0] = '|';
        labyrinth[i][gameFieldSize.x - 1] = '|';
    }
    this->start.x = 0;
    this->start.y = 0;
    this->end.x = gameFieldSize.x;
    this->end.y = gameFieldSize.y;
    this->prevStart.x = 0;
    this->prevStart.y = 0;
    this->prevEnd.x = gameFieldSize.x;
    this->prevEnd.y = gameFieldSize.y;
    this->prevDisplayMethod = DISPLAB;
}

void Labyrinth::addSnake(Snake* snake)
{
    std::list<Point> currBody;
    snake->getCoords(&currBody);
    for(auto it = currBody.begin(); it != currBody.end(); ++it)
    {
        addPoint(*it);
    }
    this->snake = snake;
}

void Labyrinth::displayHandler(Point* change[2], int size)
{
    this->updateLabyrinth(change, size);

    this->sizeHandler();

    switch (this->prevDisplayMethod)
    {
        case DISPFULL:
        {
            if(start.x == 0 and end.x == gameFieldSize.x and start.y == 0 and end.y == gameFieldSize.y)
            {
                this->displayUpdated(change, size);
            }
            else
            {
                this->displayLabyrinth();
            }
            break;
        }
        case DISPUPD:
        {
            if(start.x == 0 and end.x == gameFieldSize.x and start.y == 0 and end.y == gameFieldSize.y)
            {
                this->displayUpdated(change, size);
            }
            else
            {
                this->displayLabyrinth();
            }
            break;
        }
        case DISPLAB:
        {
            if(start.x == 0 and end.x == gameFieldSize.x and start.y == 0 and end.y == gameFieldSize.y)
            {
                this->displayFull();
            }
            else
            {
                this->displayLabyrinth();
            }
        }
    }
}

void Labyrinth::sizeHandler()
{
    Point head = this->snake->getHeadCoords(), tmp;
    getmaxyx(stdscr, tmp.y, tmp.x);
    if(tmp.y < gameFieldSize.y)
    {
        start.y = head.y - tmp.y / 2;
        end.y = head.y + tmp.y / 2;
        if(start.y < 0)
        {
            start.y = 0;
            end.y = tmp.y;
        }
        if(end.y > gameFieldSize.y)
        {
            end.y = gameFieldSize.y;
            if(start.y != 0)
            {
                start.y = gameFieldSize.y - tmp.y;
            }
        }
    } else
    {
        start.y = 0;
        end.y = gameFieldSize.y;
    }

    if(tmp.x < gameFieldSize.x)
    {
        start.x = head.x - tmp.x / 2;
        end.x = head.x + tmp.x / 2;
        if(start.x < 0)
        {
            start.x = 0;
            end.x = tmp.x;
        }
        if(end.x > gameFieldSize.x)
        {
            end.x = gameFieldSize.x;
            if(start.x != 0)
            {
                start.x = gameFieldSize.x - tmp.x;
            }
        }
    } else
    {
        start.x = 0;
        end.x = gameFieldSize.x;
    }
}

void Labyrinth::displayFull()
{
    for(int j = 0; j < gameFieldSize.y; j++)
    {
        mvaddstr(j, 0, labyrinth[j]);
    }
    this->prevDisplayMethod = DISPFULL;
}

/**
 * Drawing labyrinth to the console
 * (Should only be used at the start as it is rewriting all the points it includes
 * and not the updated)
 */
void Labyrinth::displayLabyrinth()
{
    clear();
    for(int j = start.y; j < end.y; j++)
    {
        move(j - start.y, 0);
        for(int i = start.x; i < end.x; i++)
        {
            addch(labyrinth[j][i]);
        }
    }
    this->prevDisplayMethod = DISPLAB;
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
    this->prevDisplayMethod = DISPUPD;
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
    return (this->labyrinth[p.y][p.x] == ' ');
}

bool Labyrinth::addPoint(Point p)
{
	if(this->isFree(p))
	{
        labyrinth[p.y][p.x] = p.style.letter;
		return true;
	}
	return false;
}

bool Labyrinth::remPoint(Point p)
{
    labyrinth[p.y][p.x] = ' ';
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
        for(int j = 0; j < gameFieldSize.y; j++)
        {
            fputs(labyrinth[j],file);
            fputc('\n', file);
        }
        sprintf(strout, "Succesfully saved to %s", name);
        mvaddstr(gameFieldSize.y / 2, 5, strout);
        fclose(file);
        return 1;
    }
    sprintf(strout, "Couldn't save to %s", name);
    mvaddstr(gameFieldSize.y / 2, 5, strout);
    return 0;
}

bool Labyrinth::load(char name[MAXLINE])
{
    FILE* file;
    Point tmp;
    char strout[MAXLINE];
    file = fopen(name, "r");
    if(file)
    {
        fscanf(file, "%d %d", &tmp.x, &tmp.y);
        char tmpLab[tmp.y][tmp.x];
        for(int i = 0; i < tmp.x; i++)
        {
            for(int j = 0; j < tmp.y; j++)
            {
                tmpLab[j][i] = ' ';
            }
        }
        for(int j = 1; j < tmp.y - 1; j++)
        {
            fgets(tmpLab[j], tmp.x, file);
        }
        sprintf(strout, "Succesfully loaded from %s", name);
        mvaddstr(gameFieldSize.y / 2, 5, strout);
        gameFieldSize = tmp;
        for(int i = 1; i < gameFieldSize.x - 1; i++)
        {
            for(int j = 1; j < gameFieldSize.y - 1; j++)
            {
                if(reserved.find(tmpLab[j][i]) != std::string::npos)
                {
                    labyrinth[j][i] = tmpLab[j][i];
                }
            }
        }
        fclose(file);
        return 1;
    }
    sprintf(strout, "Couldn't load from %s", name);
    mvaddstr(gameFieldSize.y / 2, 5, strout);
    return 0;
}
