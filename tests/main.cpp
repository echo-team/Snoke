/**
  * Include test headers here
  */
#include "snake_init_test.h"
#include "snake_setdirection_test.h"
//insert test for Labyrinth.setLabyrinth here
#include "game_init_test.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
