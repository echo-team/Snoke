#include <ncurses.h>
#include "Libraries/Common/common.h"
#include "Libraries/Snake/snake.h"
#include "Libraries/Game/game.h"


int main()
{
    initscr();

    Game g;
    g.init(48, 150);
    g.run();

    endwin();
    return 0;
}
