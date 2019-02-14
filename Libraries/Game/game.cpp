#include "game.h"

/**
 * gameFieldSize - a variable, which stores the dimensions of the game field(shared with snakes)
 * @type {Point} 
 * @global
 */
Point gameFieldSize;

/**
 * Initializes game
 * @param  {int} size  - size of the game field(on the edges the boundaries of the game are situated)
 * @param  {int} speed - speed of the game(1 / refresh rate) in milliseconds
 * @return {bool}      - mark of successful initialization
 */
bool Game::init(int size, int speed)
{
    gameFieldSize.x = size;
    gameFieldSize.y = size/2;
    setLabyrinth(gameFieldSize);
    setSpeed(speed);

    /**
     * Initializing the change array, containing Points to be changed in the labyrinth
     */
    this->changeSize = 2;
    this->change[0] = new Point [changeSize];
    this->change[1] = new Point [changeSize];
    return true;
}

/**
 * Main game loop
 * @return {int} - the exit code
 */
int Game::run()
{
    /**
     * Block initializing ncurses console in the current console window,
     * and setting some parameters
     */
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    #ifdef __unix__
    set_escdelay(0);
    #endif
    curs_set(0);
    keypad(stdscr, true);

    /**
     * Retrieving the size of the screen(console)
     */
    Point screenSize;
    getmaxyx(stdscr, screenSize.y, screenSize.x);

    /**
     * Initializing snake by giving it the starting position, 
     * direction of growth and starting length
     */
    Point p;
    p.x = 1;
    p.y = 1;
    int dir = 1, len = 5;
    initSnake(p, dir, len);

    /**
     * displaying the starting state of labyrinth
     */
    displayLabyrinth();

    /**
     * Initializing the Ball and generating it on the field
     */
    Ball ball;
    ball.init(gameFieldSize);
    ball.generateBall(labyrinth, change, changeSize);
    Point bCrd = ball.getCoords();
    mvaddch(bCrd.y, bCrd.x, '*');

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
        }
        if (flag)
        {
            break;
        }
        initChange(change, changeSize);

        /**
         * Setting the flag for the next iteration check
         * Moving the snake and getting the Points of a 
         * labyrinth which are to be changed in change array
         */
        flag = snake.move(labyrinth, &ball, change, changeSize) == 1;

        /**
         * Updating labyrinth with change array Points
         * and displaying/deleting added/removed Points
         */
        updateLabyrinth(change, changeSize);
        displayUpdated();

        refresh();
        flushinp();
        mSleep(speed);
    }

    endwin();
    return 0;
}

/**
 * Set's the starting labyrinth by setting the borders
 * @param {Point} gameFieldSize - dimensions(x, y) of the game field
 */
void Game::setLabyrinth(Point gameFieldSize)
{
    labyrinth = new bool* [gameFieldSize.x];
    for(int i = 0; i < gameFieldSize.x; i++)
    {
        labyrinth[i] = new bool [gameFieldSize.y];
        for(int j = 0; j < gameFieldSize.y; j++)
        {
            labyrinth[i][j] = false;
        }
    }
    for(int i = 0; i < gameFieldSize.x; i++)
    {
        labyrinth[i][0] = true;
        labyrinth[i][gameFieldSize.y - 1] = true;
    }
    for(int i = 0; i < gameFieldSize.y; i++)
    {
        labyrinth[0][i] = true;
        labyrinth[gameFieldSize.x - 1][i] = true;
    }
}

/**
 * Snake initialization with labyrinth updating
 * @param  {Point} begin  - starting Point of a snake(where the tail segment will be situated)
 * @param  {short} dir    - direction of snake's 'growth' as well as it's starting direction
 * @param  {int}   length - the length of a 'new born' snake
 * @return {bool}         - mark of whether the snake is successfully initialized
 */
bool Game::initSnake(Point begin, int dir, int length)
{
    bool flag = snake.init(begin, dir, length);
    std::list<Point> currBody;
    snake.getCoords(&currBody);
    if (flag){
        for(auto it = currBody.begin(); it != currBody.end(); it++)
        {
            labyrinth[it->x][it->y] = 1;
        }
    }
    return flag;
}

/**
 * Initialization of the change array
 * @param  {Point**} change - The pointer to an array
 * @param  {int}     size   - The size of array(max number of elements it can contain)
 * @return {bool}
 */
bool Game::initChange(Point** change, int size)
{
    for(int i = 0; i < size; i++)
    {
        change[0][i].x = -1;
        change[0][i].y = -1;
        change[1][i].x = -1;
        change[1][i].y = -1;
    }
    return true;
}

/**
 * Drawing labyrinth to the console
 * (Should only be used at the start as it is rewriting all the points it includes
 * and not the updated)
 */
void Game::displayLabyrinth()
{
    for(int i = 0; i < gameFieldSize.x; i++)
    {
        for(int j = 0; j < gameFieldSize.y; j++)
        {
            if(labyrinth[i][j]){
                mvaddch(j, i, '*');
            }
        }
    }
}

/**
 * displaying the changed Points
 */
void Game::displayUpdated()
{
    for(int i = 0; i < changeSize; i++)
    {
        mvaddch(change[1][i].y, change[1][i].x, ' ');
        mvaddch(change[0][i].y, change[0][i].x, '*');
    }
}

/**
 * Updating the labyrinth(changing the values of some Points)
 * @param {Point*} update    - 2-dimensional array of changes needed to be applied to the labyrinth
 *                 update[0] - an array containing Points to add to the labyrinth
 *                 update[1] - an array containing Points to remove from the labyrinth
 * @param {int}    size      - the longest sequence for updating [max(len(update[0], update[1]))]
 */
void Game::updateLabyrinth(Point* update[2], int size)
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

/**
 * The method to change the game speed without giving the direct access
 * @param {int} speed - speed of the game(1 / refresh rate) in milliseconds
 */
void Game::setSpeed(int speed)
{
    this->speed = speed;
}