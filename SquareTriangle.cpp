#include "SquareTriangle.h"

#include <cmath>
#include<limits>
#include <stdexcept>
int max(double a, double b, double c) {
	if (a > b && a > c)
		return 1;
	if (b > c && b > a)
		return 2;
	return 3;
}
bool is_equal(double x, double y) {
	return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}
SquareTriangle::SquareTriangle(Point aa,Point bb,Point cc):a (aa),b(bb),c(cc)
{
	double ab = sqrt(pow((b.getX() - a.getX()), 2) + pow((b.getY() - a.getY()), 2));
	double ac = sqrt(pow((c.getX() - a.getX()), 2) + pow((c.getY() - a.getY()), 2));
	double bc = sqrt(pow((c.getX() - b.getX()), 2) + pow((c.getY() - b.getY()), 2));
	if (max(ab,ac,bc) == 1) {
		if (!is_equal(pow(ab, 2), pow(ac, 2) + pow(bc, 2))) {
			throw std::invalid_argument("its not right");
		}
	}
	else if (max(ab, ac, bc) == 2) {
		if (!is_equal(pow(ac, 2), pow(ab, 2) + pow(bc, 2))) {
			throw std::invalid_argument("its not right");
		}
	}
	else if (max(ab, ac, bc) == 3) {
		if (!is_equal(pow(bc, 2), pow(ac, 2) + pow(ab, 2))) {
			throw std::invalid_argument("its not right");
		}
	}
	
}

void SquareTriangle::resize(int koef) {
	a.setX(a.getX() * koef);
	a.setY(a.getY() * koef);
	b.setX(b.getX() * koef);
	b.setY(b.getY() * koef);
	c.setX(c.getX() * koef);
	c.setY(c.getY() * koef);
	SquareTriangle(a, b, c);
}

void SquareTriangle::turn()
{
	Point z = b;
	const int angle = 90;
	auto temp = a;
	a.setX((temp.getX() - z.getX()) * cos(angle) - (temp.getY() - z.getY()) * sin(angle) + z.getX());
	a.setY((temp.getX() - z.getX()) * sin(angle) + (temp.getY() - z.getY()) * cos(angle) + z.getY());
	temp = b;
	b.setX((temp.getX() - z.getX()) * cos(angle) - (temp.getY() - z.getY()) * sin(angle) + z.getX());
	b.setY((temp.getX() - z.getX()) * sin(angle) + (temp.getY() - z.getY()) * cos(angle) + z.getY());
	temp = c;
	c.setX((temp.getX() - z.getX()) * cos(angle) - (temp.getY() - z.getY()) * sin(angle) + z.getX());
	c.setY((temp.getX() - z.getX()) * sin(angle) + (temp.getY() - z.getY()) * cos(angle) + z.getY());
	SquareTriangle(a, b, c);
}

void SquareTriangle::reflect()
{
	a.setX(-a.getX());
	b.setX(-b.getX());
	c.setX(-c.getX());
}

Point SquareTriangle::getA()
{
	return a;
}

Point SquareTriangle::getB()
{
	return b;
}

Point SquareTriangle::getC()
{
	return c;
}
