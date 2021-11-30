#include "Header.hpp"

void Point::setValueX(double x1)
{
	x = x1;
}

double Point::getValueX()
{
	return x;
}

void Point::setValueY(double y1)
{
	y = y1;
}

double Point::getValueY()
{
	return y;
}

void Point::setValueZ(double z1)
{
	z = z1;
}

double Point::getValueZ()
{
	return z;
}

void Point::generate(double min, double max)
{
	double f = (double)rand() / RAND_MAX;
	Point::x = min + f * (max - min);
	f = (double)rand() / RAND_MAX;
	Point::y = min + f * (max - min);
	f = (double)rand() / RAND_MAX;
	Point::z = min + f * (max - min);
}



double Point::distance2d(Point& p1, Point& p2) const
{
	double d = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	return d;
}

double Point::distance3d(Point& p1, Point& p2) const
{
	double d = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z));
	return d;
}