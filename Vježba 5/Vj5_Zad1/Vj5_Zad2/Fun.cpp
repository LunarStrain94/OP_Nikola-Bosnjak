#include "Header.hpp"

void Point::setValue(double x, double y, double z)
{
	Point::x = x;
	Point::y = y;
	Point::z = z;
}

void Point::generate(double min1, double max1)
{
	if (min1 > max1)
	{
		double t = min1;
		min1 = max1;
		max1 = t;
	}
	double f = (double)rand() / RAND_MAX;
	Point::x = min1 + f * (max1 - min1);
	f = (double)rand() / RAND_MAX;
	Point::y = min1 + f * (max1 - min1);
	f = (double)rand() / RAND_MAX;
	Point::z = min1 + f * (max1 - min1);
}

void Point::getValue(double& x, double& y, double& z)
{
	x = Point::x;
	y = Point::y;
	z = Point::z;
}

double Point::distance2d(Point& p1, Point& p2) const
{
	double d = sqrt((p2.x -p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	return d;
}

double Point::distance3d(Point& p1, Point& p2) const
{
	double d = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z));
	return d;
}

void Gun::setMagsize(int n)
{
	Gun::magstate = n;
}

void Gun::reload()
{
	Gun::magstate = Gun::magsize;
}

void Gun::getMagstate(int& n)
{
	n = Gun::magstate;
}

void Gun::shoot()
{
	if (Gun::magstate > 0)
		Gun::magstate -= 1;
}

bool Target::update(Gun& gun)
{
	int a = 0;
	gun.getMagstate(a);
	double x1, y1, z1, x2, y2, z2, x3, y3, z3;
	if (a <= 0)
		return false;
	Target::dwnleft.getValue(x1, y1, z1);
	Target::upright2.getValue(x2, y2, z2);
	gun.pos.getValue(x3, y3, z3);
	if (y1 < y3 && y2 > y3)
		Target::state = true;
	return Target::state;
}

void Target::generateTar(double min1, double max1)
{
	double x1, y1, z1, x2, y2, z2;
	Target::dwnleft.generate(min1, max1);
	Target::upright2.generate(min1, max1);
	Target::dwnleft.getValue(x1, y1, z1);
	Target::upright2.getValue(x2, y2, z2);
	if (y1 > y2)
	{
		Target::dwnleft.setValue(x1, y2, z1);
		Target::upright2.setValue(x2, y1, z2);
		Target::dwnleft.getValue(x1, y1, z1);
		Target::upright2.getValue(x2, y2, z2);
	}
	if (x1 > x2)
	{
		Target::dwnleft.setValue(x2, y1, z1);
		Target::upright2.setValue(x1, y2, z2);
		Target::dwnleft.getValue(x1, y1, z1);
		Target::upright2.getValue(x2, y2, z2);
	}
	if (z1 > z2)
	{
		Target::dwnleft.setValue(x1, y1, z2);
		Target::upright2.setValue(x2, y2, z1);
		Target::dwnleft.getValue(x1, y1, z1);
		Target::upright2.getValue(x2, y2, z2);
	}
	Target::dwnleft2.setValue(x1, y1, z2);
	Target::dwnright2.setValue(x2, y1, z2);
	Target::dwnright.setValue(x2, y1, z1);
	Target::upright.setValue(x2, y2, z1);
	Target::upleft.setValue(x1, y2, z1);
	Target::upleft2.setValue(x1, y2, z2);
}

//         ul2_____UR2
//          |\      |\
//      y   | \ul___|_\ur
//      ^   |  |    |  |
//      |   |__|____|  |
//  z   | dl2\ |  dr2\ |
//  '\  |     \|______\|
//    \ |      DL      dr
// ____\|__________> x
//      |\