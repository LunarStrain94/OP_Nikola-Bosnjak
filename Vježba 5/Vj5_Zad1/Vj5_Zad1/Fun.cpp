#include "Header.hpp"

void Point::setValue(double x, double y, double z)
{
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << "z: ";
	cin >> z;
	Point::x = x;
	Point::y = y;
	Point::z = z;
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

void Point::getValue(double& x, double& y, double& z)
{
	x = Point::x;
	y = Point::y;
	z = Point::z;
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