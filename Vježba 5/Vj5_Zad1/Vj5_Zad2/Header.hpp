#ifndef FUN
#define FUN
#include <iostream>
#include <math.h>
#include <vector>
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

class Gun {
	int magsize, magstate;
public:
	Point pos;
	Gun()
	{
		magsize = 12;
		magstate = 12;
	};
	void setMagsize(int n);
	int getMagstate();
	void reload();
	void shoot();
};

class Target {
	Point upright, upright2, upleft, upleft2;
	Point dwnright, dwnright2, dwnleft, dwnleft2;
	bool state;
public:
	Target()
	{
		state = false;
	};
	void generateTar(double min, double max);
	bool update(Gun& gun);
};

#endif