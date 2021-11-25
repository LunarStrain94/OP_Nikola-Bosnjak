#ifndef FUN
#define FUN
#include <iostream>
#include <math.h>
using namespace std;

class Point {
	double x, y, z;
public:
	Point()
	{
		x = 0;
		y = 0;
		z = 0;
	};
	void setValue(double x, double y, double z);
	void generate(double min, double max);
	void getValue(double& x, double& y, double& z);
	double distance2d(Point& p1, Point& p2) const;
	double distance3d(Point& p1, Point& p2) const;
};

#endif