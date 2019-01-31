#include <ncurses.h>
#include "Libraries/Common/common.cpp"
#include "Libraries/Interface/interface.h"
#include "Libraries/Screens/main.h"

int main()
{
    initscr();
    start_color();

    MainScreen main;
    main.draw();

    refresh();
    endwin();
    return 0;
}
