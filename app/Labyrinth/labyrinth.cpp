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
 * @return                - mark of succesful initialization
 */
bool Labyrinth::setLabyrinth(Point fieldSize)
{
    if(fieldSize.x > 4 && fieldSize.y > 4)
    {
        gameFieldSize = fieldSize;
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
        this->dispHandler.labyrinth = this;
        this->dispHandler.prevDisplayMethod = DISPPART;
        this->snake = NULL;

        change.initChange();
        return true;
    }
    return false;
}

/**
 * @brief   Ball initialization with labyrinth updating
 * @return       - mark of succesful initialization
 */
bool Labyrinth::initBall()
{
    this->ball.init(gameFieldSize);
    bool flag = this->generateBall();
    this->addPoint(this->ball.getCoords());
    return flag;
}

/**
 * @brief   Adding snake to the laburinth and getting the host snake(firest added snake)
 * @param   aSnake - a snake to add
 * @return         - mark of succesful addition
 */
bool Labyrinth::addSnake(Snake* aSnake)
{
    bool brFlag = false;
    std::list<Point> currBody;
    aSnake->getCoords(&currBody);
    auto it = currBody.begin();
    for(; it != currBody.end(); ++it)
    {
        if(isFree(*it) == 1)
        {
            addPoint(*it);
        }
        else
        {
            brFlag = true;
            break;
        }
    }

    if(brFlag)
    {
        for(; it != currBody.begin(); --it)
        {
            if(isFree(*it) == 0)
            {
                remPoint(*it);
            }
        }
        return false;
    }

    if(this->snake == NULL){
        this->snake = aSnake;
    }

    return true;
}

/**
 * @brief   A method which decides what dispaly method will be used in each situation
 * @param   displayMethod   - force it to use a certain display method
 */
void Labyrinth::displayHandler(int displayMethod)
{
    /*
     * Writing changes to labyrinth
     */
    this->updateLabyrinth();

    /*
     * Getting start and end values for the displaying of the labyrinth
     */
    this->sizeHandler();

    this->dispHandler.displayHandler(displayMethod);
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
 * @brief   Updating the labyrinth(changing the values of some Points)
 */
void Labyrinth::updateLabyrinth()
{
    std::deque<Point> cpChange;
    change.getRmQueue(&cpChange);

    for(auto it = cpChange.begin(); it != cpChange.end(); ++it)
    {
        remPoint(*it);
        mvaddch((*it).y, (*it).x, 'F');
    }
    change.getAddQueue(&cpChange);
    for(auto it = cpChange.begin(); it != cpChange.end(); ++it)
    {
        addPoint(*it);
    }
}

/**
 * @brief   Mark of if the asked Point is free
 * @param   p - Point to check in the labyrinth
 * @return    - mark of whether the Point is free
 */
short Labyrinth::isFree(Point p)
{
    if(p.x < gameFieldSize.x && p.y < gameFieldSize.y && p.x > -1 && p.y > -1)
    {
        return (this->labyrinth[p.y][p.x] == ' ');
    }
    else
    {
        return -1;
    }
}

/**
 * @brief   Adding Point to the labyrinth with the check of correction
 * @param   p - point to add to the labyrinth
 * @return    - mark of whether the Point was added
 */
bool Labyrinth::addPoint(Point p)
{
	if(this->isFree(p) == 1)
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

/**
 * @brief   Generate the Ball
 * @param   labyrinth  - the current state of the labyrinth object for intersection checking
 * @return             - mark of whether the ball was successfully generated
 */
bool Labyrinth::generateBall()
{
    Point chance;
    /*
     * Generate numbers until u get a free spot
     */
    while (1)
    {
        chance.x = ball.distributionX(*ball.getRng());
        chance.y = ball.distributionY(*ball.getRng());
        if ( (this->isFree(chance) == 1 || this->change.inRmQueue(chance))
         && !this->change.inAddQueue(chance))
        {
            break;
        }
    }
    ball.setCoords(chance);
    return true;
}
