/**
 * @file labyrinth.cpp
 * @author Yegor Ignatov
 * @brief realisation of Labyrinth class
 * @version 0.1
 * @date 2019-05-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "labyrinth.h"
/**
 * @brief   Sets the default values fro the variables as well as generating the labyritnh array with borders
 * @param   gameFieldSize - a size of the labyrinth
 */
void Labyrinth::setLabyrinth(Point fieldSize)
{
    /*
     * Creating the labyrinth and setting up the borders
     */
    labyrinth = new char* [fieldSize.y];
    for(int i = 0; i < fieldSize.y; i++)
    {
        labyrinth[i] = new char [fieldSize.x];
        for(int j = 0; j < fieldSize.x; j++)
        {
            labyrinth[i][j] = ' ';
        }
    }
    for(int i = 0; i < fieldSize.x; i++)
    {
        labyrinth[0][i] = '-';
        labyrinth[fieldSize.y - 1][i] = '-';
    }
    for(int i = 0; i < fieldSize.y; i++)
    {
        labyrinth[i][0] = '|';
        labyrinth[i][fieldSize.x - 1] = '|';
    }

    /*
     * Setting the default values for the Labyrinth properties
     */
    Point leftTop;
    Point rightBot;
    leftTop.x = 0;
    leftTop.y = 0;
    rightBot = fieldSize;
    this->start = leftTop;
    this->end = rightBot;
    this->prevStart = leftTop;
    this->prevEnd = rightBot;
    this->prevDisplayMethod = DISPPART;
    this->snake = NULL;
}

/**
 * @brief   Adding snake to the laburinth and getting the host snake(firest added snake)
 * @param   snake - a snake to add
 */
void Labyrinth::addSnake(Snake* aSnake)
{
    std::list<Point> currBody;
    aSnake->getCoords(&currBody);
    for(auto it = currBody.begin(); it != currBody.end(); ++it)
    {
        addPoint(*it);
    }
    if(this->snake == NULL){
        this->snake = aSnake;
    }
}

/**
 * @brief   A method which decides what dispaly method will be used in each situation
 * @param   change          - 2-dimensional array of changes needed to be applied to the labyrinth
 * @param   size            - the size of the change array
 * @param   displayMethod   - force it to use a certain display method
 */
void Labyrinth::displayHandler(Point* change[2], int size, int displayMethod)
{
    /*
     * Writing changes to labyrinth
     */
    this->updateLabyrinth(change, size);

    /*
     * Getting start and end values for the displaying of the labyrinth
     */
    this->sizeHandler();

    /*
     * checking if we are beeing asked to use a certain method
     */
    if(displayMethod >= 0)
    {
        forcedDisplay(change, size, displayMethod);
    }
    else
    {
        freeDisplay(change, size);
    }
    refresh();
    flushinp();
}

/**
 * @brief   A method, which sets start and end values depending on
 *          the position of local_player's snake head and current console size
 */
void Labyrinth::sizeHandler()
{
    Point head = this->snake->getHeadCoords();
    Point currentSize = getConsoleSize();

    /*
     * Deciding how many columns can we display and where should we start
     */
    if(currentSize.y < gameFieldSize.y)
    {
        start.y = head.y - currentSize.y / 2;
        end.y = head.y + currentSize.y / 2 + currentSize.y % 2;
        if(start.y < 0)
        {
            start.y = 0;
            end.y = currentSize.y;
        }
        if(end.y >= gameFieldSize.y)
        {
            end.y = gameFieldSize.y;
            if(start.y != 0)
            {
                start.y = gameFieldSize.y - currentSize.y;
            }
        }
    } else
    {
        start.y = 0;
        end.y = gameFieldSize.y;
    }

    /*
     * Deciding how many rows can we display and where should we start
     */
    if(currentSize.x < gameFieldSize.x)
    {
        start.x = head.x - currentSize.x / 2;
        end.x = head.x + currentSize.x / 2 + currentSize.x % 2;
        if(start.x < 0)
        {
            start.x = 0;
            end.x = currentSize.x;
        }
        if(end.x >= gameFieldSize.x)
        {
            end.x = gameFieldSize.x;
            if(start.x != 0)
            {
                start.x = gameFieldSize.x - currentSize.x;
            }
        }
    } else
    {
        start.x = 0;
        end.x = gameFieldSize.x;
    }
}

/**
 * @brief   got an extra stimulus for displaying in a certain method
 * @param   change          - 2-dimensional array of changes needed to be applied to the labyrinth
 * @param   size            - the size of the change array
 * @param   displayMethod   - a method that is beeing force-called
 */
void Labyrinth::forcedDisplay(Point* change[2], int size, int displayMethod)
{
    /*
     * Deciding what disply method to use
     */
    switch (displayMethod)
    {
        case DISPFULL:
        {
            if(start.x == 0 && end.x == gameFieldSize.x && start.y == 0 && end.y == gameFieldSize.y)
            {
                this->displayFull();
            }
            else
            {
                this->displayPartialy();
            }
            break;
        }
        case DISPUPD:
        {
            if(start.x == 0 && end.x == gameFieldSize.x && start.y == 0 && end.y == gameFieldSize.y)
            {
                this->displayUpdated(change, size);
            }
            else
            {
                this->displayPartialy();
            }
            break;
        }
        case DISPPART:
        {
            this->displayPartialy();
            break;
        }
        default:
        {
            this->displayPartialy();
        }
    }
}

/**
 * @brief   No extra stimulus, displaying the default way
 * @param   change  - 2-dimensional array of changes needed to be applied to the labyrinth
 * @param   size    - the size of the change array
 */
void Labyrinth::freeDisplay(Point* change[2], int size)
{
    /*
     * Deciding what disply method to use
     */
    switch (this->prevDisplayMethod)
    {
        case DISPFULL:
        {
            if(start.x == 0 && end.x == gameFieldSize.x && start.y == 0 && end.y == gameFieldSize.y)
            {
                this->displayUpdated(change, size);
            }
            else
            {
                this->displayPartialy();
            }
            break;
        }
        case DISPUPD:
        {
            if(start.x == 0 && end.x == gameFieldSize.x && start.y == 0 && end.y == gameFieldSize.y)
            {
                this->displayUpdated(change, size);
            }
            else
            {
                this->displayPartialy();
            }
            break;
        }
        case DISPPART:
        {
            if(start.x == 0 && end.x == gameFieldSize.x && start.y == 0 && end.y == gameFieldSize.y)
            {
                this->displayFull();
            }
            else
            {
                this->displayPartialy();
            }
            break;
        }
        default:
        {
            this->displayPartialy();
        }
    }
}

/**
 * @brief   redraw every Point of the labyrinth
 */
void Labyrinth::displayFull()
{
    for(int j = 0; j < gameFieldSize.y; j++)
    {
        mvaddstr(j, 0, labyrinth[j]);
    }
    this->prevDisplayMethod = DISPFULL;
}

/**
 * @brief   display labyrinth partialy, using the start and end Points
 */
void Labyrinth::displayPartialy()
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
    this->prevDisplayMethod = DISPPART;
}

/**
 * @brief   draw only the changed Points when the labyrinth is being fully displayed
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
 * @brief   Updating the labyrinth(changing the values of some Points)
 * @param   update - 2-dimensional array of changes needed to be applied to the labyrinth
 * @param   size   - the longest sequence for updating [max(len(update[0], update[1]))]
 */
void Labyrinth::updateLabyrinth(Point* update[2], int size)
{
    Point p;
    for(int i = 0; i < size; i++)
    {
        p = update[0][i];
        if(p.x >= 0 && p.y >= 0)
        {
            addPoint(p);
        }
        p = update[1][i];
        if(p.x >= 0 && p.y >= 0)
        {
            remPoint(p);
        }
    }
}

/**
 * @brief   Mark of if the asked Point is free
 * @param   p - Point to check in the labyrinth
 * @return    - mark of whether the Point is free
 */
bool Labyrinth::isFree(Point p)
{
    return (this->labyrinth[p.y][p.x] == ' ');
}

/**
 * @brief   Adding Point to the labyrinth with the check of correction
 * @param   p - point to add to the labyrinth
 * @return    - mark of whether the Point was added
 */
bool Labyrinth::addPoint(Point p)
{
	if(this->isFree(p))
	{
        labyrinth[p.y][p.x] = p.style.letter;
		return true;
	}
	return false;
}

/**
 * @brief   Remove Point from the labyrinth
 * @param   p - point to remove from the labyrinth
 * @return    - mark of whether the Point was removed
 */
bool Labyrinth::remPoint(Point p)
{
    labyrinth[p.y][p.x] = ' ';
	return true;
}

/**
 * @brief   Method to save labyritnh(borders and obstacles, defined in reserved string) to the file
 * @param   name - name of the file, where to sace the labyrinth
 * @return       - mark of whether the labyrinth was successfully saved
 */
bool Labyrinth::save(char name[MAXLINE])
{
    FILE* file;
    char strout[MAXLINE];
    file = fopen(name, "w");
    if(file)
    {
        /*
         * Printing the dimensions of the gamefield
         */
        fprintf(file, "%d %d\n", gameFieldSize.x, gameFieldSize.y);

        /*
         * Printing the lines of labyrinth to the file one by one
         */
        for(int j = 0; j < gameFieldSize.y; j++)
        {
            fputs(labyrinth[j], file);
            fputc('\n', file);
        }
        fclose(file);

        /*
         * Putting a message of successful writing
         */
        snprintf(strout, sizeof(strout), "Succesfully saved to %s", name);
        mvaddstr(gameFieldSize.y / 2, 5, strout);
        return true;
    }
    /*
     * Putting a message of an occured error
     */
    snprintf(strout, sizeof(strout), "Couldn't save to %s", name);
    mvaddstr(gameFieldSize.y / 2, 5, strout);
    return false;
}

/**
 * @brief   Mehod to load labyrinth from the file
 * @param   name - name of the file to read from
 * @return       - mark os successful loading
 */
bool Labyrinth::load(char name[MAXLINE])
{
    FILE* file;
    Point scannedSize;
    char strout[MAXLINE];
    file = fopen(name, "r");
    if(file)
    {
        /*
         * Getting the dimensions of the labyrinth and creating a temporary labyrinth
         */
        fscanf(file, "%hd %hd", &scannedSize.x, &scannedSize.y);
        char tmpLab[scannedSize.y][scannedSize.x];
        for(int i = 0; i < scannedSize.x; i++)
        {
            for(int j = 0; j < scannedSize.y; j++)
            {
                tmpLab[j][i] = ' ';
            }
        }

        /*
         * Getting lines of the labyrinth
         */
        for(int j = 0; j < scannedSize.y; j++)
        {
            fgets(tmpLab[j], scannedSize.x, file);
        }
        fclose(file);

        /*
         * Setting the new gameFieldSize and copying the borders and obstacles from the temporary labyrinth
         */
        gameFieldSize = scannedSize;
        for(int i = 0; i < gameFieldSize.x; i++)
        {
            for(int j = 0; j < gameFieldSize.y; j++)
            {
                if(reserved.find(tmpLab[j][i]) != std::string::npos)
                {
                    labyrinth[j][i] = tmpLab[j][i];
                }
            }
        }
        /*
         * Putting a message of successful loading
         */
        snprintf(strout, sizeof(strout), "Succesfully loaded from %s", name);
        mvaddstr(gameFieldSize.y / 2, 5, strout);
        return 1;
    }
    /*
     * Putting message of occured error
     */
    snprintf(strout, sizeof(strout), "Couldn't load from %s", name);
    mvaddstr(gameFieldSize.y / 2, 5, strout);
    return 0;
}
