#ifndef SQUARE
#define SQUARE
#include "Point.h"
class SquareTriangle
{
public:
	SquareTriangle(Point a,Point b, Point c);
	void resize(int koef);
	void turn();
	void reflect();
	Point getA();
	Point getB();
	Point getC();

	double getArea();

	double getPerimeter();

	double getAngles();
	
private:
	Point a,b,c;
	double ab, ac, bc;
	int maxside;
};
#endif

