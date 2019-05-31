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
 * Handler for SIGWINCH signal
 * @param  sig      SIGWINCH signal code
 */
void resizeHandler(int sig)
{
    endwin();
    sleepHandler();
    refresh();
    addSleep();
}

/**
 * @brief   Initializes game
 * @param   size   - size of the game field(size - 2 columns, size/2 - 2 rows)
 * @param   speed  - speed of the game(1 / refresh rate) in milliseconds
 * @param   loops - for how many loops the game  should run
 * @return        - mark of successful initialization
 */
bool Game::init(int size, int speed, int loops)
{
    if(size > 10)
    {
        gameFieldSize.x = size;
        gameFieldSize.y = size/2;
        this->labyrinth.setLabyrinth(gameFieldSize);
        this->setSpeed(speed);
        this->setLoops(loops);

        return true;
    }
    return false;
}

/**
 * @brief sets loops with some error holding
 * @param loops - amount of loops game will run (-1 for unlimmited)
 */
void Game::setLoops(int loops)
{
    this->loops = loops > 0 ? loops : -1;
}



/**
 * @brief   Main game loop
 * @return  - the exit code
 */
int Game::run()
{
    signal(SIGWINCH, resizeHandler);

    /*
     * Initializing snake by giving it the starting position,
     * direction of growth and starting length
     */
    Point startPos;
    startPos.x = 1;
    startPos.y = 1;
    int dir = 1;
    int len = 5;
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
    while (!flag && loops != 0)
    {
        int command = getch();
        switch (command)
        {
            case ERR:
            {
                break;
            }
            case KEY_UP:
            {
                snake.setDirection(MVUP);
                break;
            }
            case KEY_DOWN:
            {
                snake.setDirection(MVDOWN);
                break;
            }
            case KEY_LEFT:
            {
                snake.setDirection(MVLEFT);
                break;
            }
            case KEY_RIGHT:
            {
                snake.setDirection(MVRIGHT);
                break;
            }
            case 'q':
            {
                flag = true;
                break;
            }
            default:
            {
                break;
            }
        }
        if (flag)
        {
            break;
        }
        labyrinth.change.initQueue();

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
        if(loops > 0)
        {
            loops--;
        }
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
bool Game::initSnake(Point begin, short dir, int length)
{
    bool initFlag = snake.init(begin, dir, length);
    bool addFlag = initFlag ? labyrinth.addSnake(&snake) : false;
    return initFlag && addFlag;
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
