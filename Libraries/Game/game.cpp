#include "game.h"

/**
 * @global {Point} gameFieldSize - a variable, which stores the dimensions of the game field
 */
Point gameFieldSize;

/**
 * @function Initializes game
 * @param {int} size - size of the game field(on the edges the boundaries of the game are situated)
 * @param {int} sp - speed of the game(1 / refresh rate) in milliseconds
 * @return {bool} mark of successful initialization
 */
bool Game::init(int size, int sp)
{
    gameFieldSize.x = size;
    gameFieldSize.y = size/2;
    setLabyrinth(gameFieldSize);
    setSpeed(sp);
    return true;
}

/**
 * @function Main game loop
 * @return {int} the exit code
 */
int Game::run()
{

    initscr();

    noecho();
    nodelay(stdscr, TRUE);
    set_escdelay(0);

    Point screenSize;
    getmaxyx(stdscr, screenSize.y, screenSize.x);

    Point p, g;
    p.x = 1;
    p.y = 1;
    int dir = 1, len = 5;
    initSnake(p, dir, len);

    curs_set(0);
    keypad(stdscr, true); 
    bool flag = false;

    Ball ball;
    ball.init(gameFieldSize);
    ball.generateBall(labyrinth);

    Point* change[2];
    change[0] = new Point [1];
    change[1] = new Point [1];

    std::list<Point> currBody;
    while ( !flag )
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
        flag = snake.move(labyrinth, &ball, change);
        updateLabyrinth(change, 1);
        clear();
        displayLabyrinth();
        snake.getCoords(&currBody);
        for(auto it = currBody.begin(); it != currBody.end(); it++)
        {
            mvaddch(it->y, it->x, '*');
        }
        g = ball.getCoords();
        mvaddch(g.y, g.x, '*');
        flushinp();
        mSleep(speed);
        refresh();
        if (flag)
        {
            break;
        }
    }

    endwin();
    return 0;
}

/**
 * @function Set's the starting labyrinth
 * @param {Point} dimensions - dimensions of the game field
 */
void Game::setLabyrinth(Point dimensions)
{
    labyrinth = new bool* [dimensions.x];
    for(int i = 0; i < dimensions.x; i++)
    {
        labyrinth[i] = new bool [dimensions.y];
    }
    for(int i = 0; i < dimensions.x; i++)
    {
        labyrinth[i][0] = 1;
        labyrinth[i][dimensions.y - 1] = 1;
    }
    for(int i = 0; i < dimensions.y; i++)
    {
        labyrinth[0][i] = 1;
        labyrinth[dimensions.x - 1][i] = 1;
    }
}

/**
 * @function Snake initialization with labyrinth updating
 * @param {Point} begin  - starting Point of a snake(where the tail segment will be situated)
 * @param {short} dir    - direction of snake's 'growth' as well as it's starting direction
 * @param {int}   length - the length of a 'new born' snake
 * @return {bool} - mark of whether the snake is successfully initialized
 */
bool Game::initSnake(Point begin, int dir, int length)
{
    bool q = snake.init(begin, dir, length);
    std::list<Point> currBody;
    snake.getCoords(&currBody);
    if (q){
        for(auto it = currBody.begin(); it != currBody.end(); it++)
        {
            labyrinth[it->x][it->y] = 1;
        }
    }
    return q;
}

/**
 * @function Drawing labyrinth to the console
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
 * @function Updating the labyrinth(changing the values of some Points)
 * @param {Point*} update    - 2-dimensional array of changes needed to be applied to the labyrinth
 *                 update[0] - an array containing Points to add to the labyrinth
 *                 update[1] - an array containing Points to remove from the labyrinth
 * @param {int} size - the longest sequence for updating [max(len(update[0], update[1]))]
 */
void Game::updateLabyrinth(Point* update[2],int size)
{
    for(int i = 0; i < size; i++)
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
 * @function The method to change the game speed without giving the direct access
 * @param {int} sp - speed of the game(1 / refresh rate) in milliseconds
 */
void Game::setSpeed(int sp)

{
    speed = sp;
}