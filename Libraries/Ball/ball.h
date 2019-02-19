#ifndef BALL_H
#define BALL_H
#include "../Common/common.h"
#include "../Labyrinth/labyrinth.h"
#include <random>
#include <ctime>


/**
 * Describes the Ball entity of the game
 * @prop {Point}                         position      - a Coordinates(x, y) of a Ball in the Console window
 * @prop {mt19937}                       rng           - the variable, responible for the 'random' during the game
 * @prop {uint32_t}                      seed_val      - value 'feeded' to the 'random' generator
 * @prop {uniform_int_distribution<int>} distributionX - an equally likely int distribution for x coordinate of a Ball
 * @prop {uniform_int_distribution<int>} distributionY - an equally likely int distribution for y coordinate of a Ball
 */
class Ball
{
    private:
        Point position;
        std::mt19937 rng;
        uint32_t seed_val;
        std::uniform_int_distribution<int> distributionX;
        std::uniform_int_distribution<int> distributionY;
    public:
        bool init(Point dim);
        bool generateBall(Labyrinth labyrinth, Point* change[2], int changeSize);
        Point getCoords();
};
#endif