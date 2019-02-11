#include <ncurses.h>
#include "Libraries/Common/common.h"
#include "Libraries/Snake/snake.h"
#include "Libraries/Game/game.h"


int main()
{
    Game g;
    g.init(60, 100);
    g.run();
    return 0;
}
