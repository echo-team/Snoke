#include <ncurses.h>
#include "Screens/mainMenu.h"
#include "Game/game.h"
#include "iostream"

int main()
{
    /*
     * Block initializing ncurses console in the current console window,
     * and setting some parameters
     */
    initscr();
    start_color();
    noecho();
    nodelay(stdscr, true);
    curs_set(0);
    keypad(stdscr, true);

    Game g;
    g.init(70, 150, -1);
    int gameReturn = g.run();

    refresh();
    endwin();
    switch(gameReturn)
    {
        case 1:
        {
            std::cout << "Incorrect Snake initialization, failed at function Game::initSnake" << std::endl;
            return 1;
        }
        default:
            return 0;
    }
}
