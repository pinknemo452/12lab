#ifndef SQUARE
#define SQUARE
#include "Point.h"
class SquareTriangle
{
public:
	SquareTriangle(Point a,Point b, Point c);
	void resize();
private:
	Point a,b,c;
};
#endif

