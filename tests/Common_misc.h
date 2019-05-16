#ifndef COMMON_MISC_H
#define COMMON_MISC_H

#include "shared.h"

TEST(Common_misc, PointEqual)
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

TEST(Common_misc, PointNotEqual)
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

TEST(Common_misc, PointOstream)
{
    Point p;
    p.x = 10;
    p.y = 150;
    std::cout << p << std::endl;
    SUCCEED();
}

#endif // COMMON_MISC_H
