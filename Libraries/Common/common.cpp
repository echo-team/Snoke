#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <chrono>
#include <thread>

/**
 * Coordinates of the cell in console window
 * @prop {short} x - x coordinate in console window
 * @prop {short} y - y coordinate in console window
 */
typedef struct {
    short x, y;
} Point;


/**
 * @override Operation '<<' override for the Point type
 */
inline std::ostream& operator << (std::ostream &s, Point p){
    s << '(' << p.x << ',' << p.y << ')';
    return s;
}

/**
 * Style of the cell in console window
 * @prop {char}  letter - symbol in the cell
 * @prop {short} fg     - foreground color of the cell
 * @prop {short} bg     - beckground color of the cell
 */
typedef struct {
    char letter;
    int fg, bg;
} PointStyle;


/**
 * @function Cross-platform sleep function cover
 * @param {int} time - time the game will 'freeze' for in milliseconds
 */
inline void mSleep(int time){
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

#endif