#include <ncurses.h>
#include "Screens/mainMenu.h"
#include "Game/game.h"

int main()
{
    initscr();
    start_color();

    /*MainMenu main;
    main.draw();
    */

    Game g;
    g.init(70, 150);
    g.run();

    refresh();
    endwin();
    return 0;
}
