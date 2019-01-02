#include <ncurses.h>
#include "Libraries/Common/common.h"
#include "Libraries/Interface/interface.h"
#include "Libraries/Screens/main.h"

int main()
{
    initscr();

    MainScreen main;
    main.draw();

    refresh();
    endwin();
    return 0;
}
