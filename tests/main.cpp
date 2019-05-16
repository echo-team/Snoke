/**
  * Include test headers here
  */
#include "Common_misc.h"
#include "Snake_init.h"
#include "Snake_setDirection.h"
#include "Labyrinth_setLabyrinth.h"
#include "Labyrinth_addSnake.h"
#include "Ball_init.h"
#include "Labyrinth_generateBal.h"
#include "Snake_move.h"
#include "Game_init.h"
#include "Labyrinth_displayHandler.h"
#include "Labyrinth_save.h"
#include "Labyrinth_load.h"
#include "Game_run.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
