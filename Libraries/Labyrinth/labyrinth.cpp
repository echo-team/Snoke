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

/**
 * Drawing labyrinth to the console
 * (Should only be used at the start as it is rewriting all the points it includes
 * and not the updated)
 */
void Labyrinth::displayLabyrinth(Point* change[2], int size)
{
    Point tmp, start, end;
    char string[9];
    getmaxyx(stdscr, tmp.y, tmp.x);
    Point head = this->snake->getHeadCoords();
    bool flag = 0;
    sprintf(string, "%d %d", (int)tmp.y, (int)tmp.x);

    if(tmp.y < gameFieldSize.y)
    {
        flag = 1;
        start.y = head.y - tmp.y / 2;
        end.y = head.y + tmp.y / 2;
        if(start.y < 0)
        {
            start.y = 0;
        }
        if(end.y > gameFieldSize.y)
        {
            end.y = gameFieldSize.y;
        }
    } else
    {
        start.y = 0;
        end.y = gameFieldSize.y;
    }

    if(tmp.x < gameFieldSize.x)
    {
        flag = 1;
        start.x = head.x - tmp.x / 2;
        end.x = head.x + tmp.x / 2;
        if(start.x < 0)
        {
            start.x = 0;
        }
        if(end.x > gameFieldSize.x)
        {
            end.x = gameFieldSize.x;
        }
    } else
    {
        start.x = 0;
        end.x = gameFieldSize.x;
    }

    if(!flag)
    {
        displayUpdated(change, size);
        return;
    }

    clear();
    for(int j = start.y; j < end.y; j++)
    {
        move(j - start.y, 0);
        for(int i = start.x; i < end.x; i++)
        {
            addch(labyrinth[j][i]);
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
