#include "ball.h"

typedef std::mt19937 MyRNG;
uint32_t seed_val;

MyRNG rng;

Ball::Ball(Point dim){
    seed_val = time(NULL);
    rng.seed(seed_val);
    std::uniform_int_distribution<int> distribution1(0, dim.x - 1);
    distributionX = distribution1;
    std::uniform_int_distribution<int> distribution2(0, dim.y - 1);
    distributionY = distribution2;
}

bool Ball::generateBall(bool** labyrinth){
    Point p;
    //auto dice = std::bind ( distribution, generator );
    //Generate numbers until u get a free spot
    while (1){
        p.x = distributionX(rng);
        p.y = distributionY(rng);
        if (labyrinth[p.x][p.y] == false)
            break;
    }
    position.x = p.x;
    position.y = p.y;
    return true; 
}

Point Ball::getCoords(){
    return position;
}

