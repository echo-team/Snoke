#ifndef LABYRINTH_SETLABYRINTH_H
#define LABYRINTH_SETLABYRINTH_H


#include "shared.h"
#include "Labyrinth/labyrinth.h"

/**
 * @brief Labyrinth class object can be created
 */
TEST(Labyrinth_setLabyrinth, test0){
    Labyrinth labyrinth;
    SUCCEED();
}

/**
 * @brief method runs with normal parameters
 */
TEST(Labyrinth_setLabyrinth, test1) {
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
TEST(Labyrinth_setLabyrinth, test2) {
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

#endif // LABYRINTH_SETLABYRINTH_H
