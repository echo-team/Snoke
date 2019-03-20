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
    this->labyrinth.setLabyrinth(gameFieldSize);
    this->labyrinth.load("testload");
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
    noecho();
    nodelay(stdscr, true);
    #ifdef __unix__
    //set_escdelay(0);
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
     * Initializing the Ball and generating it on the field
     */
    Ball ball;
    initBall(&ball);

    /**
     * displaying the starting state of labyrinth
     */
    labyrinth.displayLabyrinth();

    bool flag = false;
    while (!flag)
    {
        int command = getch();
        switch (command)
        {
            case ERR:
                break;
            case KEY_UP:
            case 'w':
                snake.setDirection(MVUP);
                break;
            case KEY_DOWN:
            case 's':
                snake.setDirection(MVDOWN);
                break;
            case KEY_LEFT:
            case 'a':
                snake.setDirection(MVLEFT);
                break;
            case KEY_RIGHT:
            case 'd':
                snake.setDirection(MVRIGHT);
                break;
            case 'q':
                flag = true;
                break;
            case 'c':
                labyrinth.save("testsave");
                refresh();
                flushinp();
                labyrinth.displayLabyrinth();
                mSleep(speed * 2);
                continue;
        }
        if (flag)
        {
            break;
        }
        wipeChange(change, changeSize);

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
        labyrinth.updateLabyrinth(change, changeSize);
        labyrinth.displayUpdated(change, changeSize);

        refresh();
        flushinp();
        mSleep(speed);
    }
    return 0;
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
    if (!flag){
        labyrinth.addSnake(currBody);
    }
    return flag;
}

bool Game::initBall(Ball* ball)
{
    ball->init(gameFieldSize);
    ball->generateBall(labyrinth, change, changeSize);
    labyrinth.addPoint(ball->getCoords());
    return true;
}

/**
 * Initialization of the change array
 * @param  {Point**} change - The pointer to an array
 * @param  {int}     size   - The size of array(max number of elements it can contain)
 * @return {bool}
 */
bool Game::wipeChange(Point** change, int size)
{
    Point p;
    p.x = -1;
    p.y = -1;
    p.style.bg = 0;
    p.style.fg = 0;
    p.style.letter = 0;
    for(int i = 0; i < size; i++)
    {
        change[0][i] = p;
        change[1][i] = p;
    }
    return true;
}



/**
 * The method to change the game speed without giving the direct access
 * @param {int} speed - speed of the game(1 / refresh rate) in milliseconds
 */
void Game::setSpeed(int speed)
{
    this->speed = speed;
}
