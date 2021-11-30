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
	void setValueX(double x1);
	double getValueX();
	void setValueY(double y1);
	double getValueY();
	void setValueZ(double z1);
	double getValueZ();
	void generate(double min, double max);
	double distance2d(Point& p1, Point& p2) const;
	double distance3d(Point& p1, Point& p2) const;
};

#endif