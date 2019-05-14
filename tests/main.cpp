/**
  * Include test headers here
  */
#include "common_test.h"
#include "snake_init_test.h"
#include "snake_setdirection_test.h"
#include "labyrinth_setlabyrinth_test.h"
#include "labyrinth_addsnake_test.h"
#include "ball_init_test.h"
#include "labyrinth_generateball_test.h"
#include "snake_move_test.h"
#include "game_init_test.h"
#include "labyrinth_displayhandler_test.h"
#include "labyrinth_save_test.h"
#include "labyrinth_load_test.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
