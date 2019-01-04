#include <ncurses.h>
#include "Libraries/common.cpp"
#include "Libraries/snake.h"
#include "Libraries/game.h"


int main()
{
	Game g;
	g.init();
	g.run();
	return 0;
}
