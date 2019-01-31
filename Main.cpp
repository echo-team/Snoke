#include <ncurses.h>
#include "Libraries/Common/common.cpp"
#include "Libraries/Snake/snake.h"
#include "Libraries/Game/game.h"


Point dim;

int main()
{
	Game g;
	g.init(40, 100);
	g.run();
	return 0;
}
