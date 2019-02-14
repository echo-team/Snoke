#include <ncurses.h>
#include "Libraries/Common/common.h"
#include "Libraries/Snake/snake.h"
#include "Libraries/Game/game.h"


int main()
{
	/**
     * Block initializing ncurses console in the current console window,
     * and setting some parameters
     */
    initscr();
    noecho();
    nodelay(stdscr, true);
    #ifdef __unix__
    set_escdelay(0);
    #endif
    curs_set(0);
    keypad(stdscr, true);

    Game g;
    g.init(48, 150);
    g.run();

    endwin();
    return 0;
}
