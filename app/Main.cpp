#include <ncurses.h>
#include "Screens/mainMenu.h"
#include "Game/game.h"
#include "iostream"

int main()
{
    initscr();
    start_color();

    /*MainMenu main;
    main.draw();
    */

    Game g;
    g.init(70, 150, -1);
    int retVal = g.run();

    refresh();
    endwin();
    switch(retVal)
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
