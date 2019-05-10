#ifndef LABYRINTH_SETLABYRINTH_TEST_H
#define LABYRINTH_SETLABYRINTH_TEST_H


#include "shared.h"
#include "Labyrinth/labyrinth.h"

/**
 * @brief Labyrinth class object can be created
 */
TEST(labyrinth_init_test, test0){
    Labyrinth labyrinth;
    SUCCEED();
}

/**
 * @brief method runs with normal parameters
 */
TEST(labyrinth_init_test, test1) {
    Labyrinth labyrinth;
    Point size;
    size.x = 5;
    size.y = 5;
    bool retVal = labyrinth.setLabyrinth(size);
    if(retVal)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }
}

/**
 * @brief negative test with incorrect input parameters
 */
TEST(labyrinth_init_test, test2) {
    Labyrinth labyrinth;
    Point size;
    size.x = 3;
    size.y = -2;
    bool retVal = labyrinth.setLabyrinth(size);
    if(!retVal)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }
}

#endif // LABYRINTH_SETLABYRINTH_TEST_H
