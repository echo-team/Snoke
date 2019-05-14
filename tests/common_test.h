#ifndef COMMON_TEST_H
#define COMMON_TEST_H

#include "shared.h"

TEST(common_test, PointEqual)
{
    Point p;
    Point q;
    p.x = 1;
    p.y = 10;
    q.x = 1;
    q.y = 10;
    if(p==q)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }
}

TEST(common_test, PointNotEqual)
{
    Point p;
    Point q;
    p.x = 1;
    p.y = 10;
    q.x = 2;
    q.y = 50;
    if(!(p==q))
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }
}

#endif // COMMON_TEST_H
