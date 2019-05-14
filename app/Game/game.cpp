/**
 * @file game.cpp
 * @author Yegor Ignatov
 * @brief realisation of Game class
 * @version 0.1
 * @date 2019-05-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "game.h"

/**
 * @var Point gameFieldSize
 * size of a game field(x, y)
 */
Point gameFieldSize;

/**
 * @brief   Initializes game
 * @param   size  - size of the game field(size - 2 columns, size/2 - 2 rows)
 * @param   speed - speed of the game(1 / refresh rate) in milliseconds
 * @return        - mark of successful initialization
 */
bool Game::init(int size, int speed)
{
    if(size > 10)
    {
        gameFieldSize.x = size;
        gameFieldSize.y = size/2;
        this->labyrinth.setLabyrinth(gameFieldSize);
        this->setSpeed(speed);

        return true;
    }
    return false;
}



/**
 * @brief   Main game loop
 * @return  - the exit code
 */
int Game::run()
{
    /*
     * Block initializing ncurses console in the current console window,
     * and setting some parameters
     */
    noecho();
    nodelay(stdscr, true);
    #ifdef __unix__
    set_escdelay(0);
    #endif
    curs_set(0);
    keypad(stdscr, true);

    /*
     * Initializing snake by giving it the starting position,
     * direction of growth and starting length
     */
    Point startPos;
    startPos.x = 1;
    startPos.y = 1;
    int dir = 1, len = 5;
    if(!initSnake(startPos, dir, len))
    {
        return 1;
    }

    /*
     * Initializing the Ball and generating it on the field
     */
    labyrinth.initBall();

    /*
     * displaying the starting state of labyrinth(forcing to display it Full if possible)
     */
    labyrinth.displayHandler(DISPFULL);

    bool flag = false;
    while (!flag)
    {
        int command = getch();
        switch (command)
        {
            case ERR:
                break;
            case KEY_UP:
                snake.setDirection(MVUP);
                break;
            case KEY_DOWN:
                snake.setDirection(MVDOWN);
                break;
            case KEY_LEFT:
                snake.setDirection(MVLEFT);
                break;
            case KEY_RIGHT:
                snake.setDirection(MVRIGHT);
                break;
            case 'q':
                flag = true;
                break;
            case 's':
                char fName[] = "testsave";
                labyrinth.save(fName);
                labyrinth.displayHandler();
                mSleep(speed * 2);
                labyrinth.displayHandler(DISPFULL);
                continue;
        }
        if (flag)
        {
            break;
        }
        labyrinth.change.initChange();

        /*
         * Setting the flag for the next iteration check
         * Moving the snake and getting the Points of a
         * labyrinth which are to be changed in change array
         */
        flag = snake.move(&labyrinth) == 1;

        /*
         * Updating labyrinth with change array Points
         * and displaying/deleting added/removed Points
         */
        labyrinth.displayHandler();

        mSleep(speed);
    }
    return 0;
}

/**
 * @brief   Snake initialization with labyrinth updating
 * @param   begin  - starting Point of a snake(where the tail segment will be situated)
 * @param   dir    - direction of snake's 'growth' as well as it's starting direction
 * @param   length - the length of a 'new born' snake
 * @return         - mark of whether the snake is successfully initialized
 */
bool Game::initSnake(Point begin, int dir, int length)
{
    bool flag = snake.init(begin, dir, length);
    bool retVal = false;
    if (flag){
        retVal = labyrinth.addSnake(&snake);
    }
    return flag && retVal;
}

/**
 * @brief   The method to change the game speed without giving the direct access
 *          and some error handling
 * @param   speed - speed of the game(1 / refresh rate) in milliseconds
 */
void Game::setSpeed(int speed)
{
    if(speed > 100)
    {
        if(speed < 1000)
        {
            this->speed = speed;
        }
        else
        {
            this->speed = 1000;
        }
    }
    else
    {
        this->speed = 100;
    }
}
