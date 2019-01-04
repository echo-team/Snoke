#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <deque>


typedef struct {
	short x, y;
} Point;

inline std::ostream& operator << (std::ostream &s, Point p){
	s << '(' << p.x << ',' << p.y << ')';
	return s;
}

typedef struct {
	char letter;
	int fg, bg;
} PointStyle;

#endif