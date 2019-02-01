#ifndef BALL_H
#define BALL_H
#include "../Common/common.cpp"
#include <random>
#include <ctime>

class Ball
{
private:
    Point position;
    std::uniform_int_distribution<int> distributionX;
    std::uniform_int_distribution<int> distributionY;
public:
    Ball(Point dim);
    bool generateBall(bool** labyrinth);
    Point getCoords();
};
#endif