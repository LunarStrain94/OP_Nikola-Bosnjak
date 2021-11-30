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

void Point::generate(double min1, double max1)
{
	if (min1 > max1)
	{
		double t = min1;
		min1 = max1;
		max1 = t;
	}
	double f = (double)rand() / RAND_MAX;
	x = min1 + f * (max1 - min1);
	f = (double)rand() / RAND_MAX;
	y = min1 + f * (max1 - min1);
	f = (double)rand() / RAND_MAX;
	z = min1 + f * (max1 - min1);
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
	magstate = n;
}

void Gun::reload()
{
	magstate = magsize;
}

int Gun::getMagstate()
{
	return magstate;
}

void Gun::shoot()
{
	if (magstate > 0)
		magstate -= 1;
}

bool Target::update(Gun& gun)
{
	double x1, y1, z1, x2, y2, z2, y3;
	x1 = dwnleft.getValueX();
	dwnleft.setValueX(x1);
	y1 = dwnleft.getValueY();
	dwnleft.setValueY(y1);
	z1 = dwnleft.getValueZ();
	dwnleft.setValueZ(z1);

	x2 = upright2.getValueX();
	upright2.setValueX(x2);
	y2 = upright2.getValueY();
	upright2.setValueY(y2);
	z2 = upright2.getValueZ();
	upright2.setValueZ(z2);

	y3 = gun.pos.getValueY();
	return (y1 < y3 && y2 > y3);
}

void Target::generateTar(double min1, double max1)
{
	double x1, y1, z1, x2, y2, z2;
	dwnleft.generate(min1, max1);
	upright2.generate(min1, max1);

	x1 = dwnleft.getValueX();
	y1 = dwnleft.getValueY();
	z1 = dwnleft.getValueZ();
	x2 = upright2.getValueX();
	y2 = upright2.getValueY();
	z2 = upright2.getValueZ();

	if (y1 > y2)
	{
		dwnleft.setValueY(y2);
		upright2.setValueY(y1);
		y1 = dwnleft.getValueY();
		y2 = upright2.getValueY();

	}
	if (x1 > x2)
	{
		dwnleft.setValueX(x2);
		upright2.setValueX(x1);
		y1 = dwnleft.getValueX();
		y2 = upright2.getValueX();
	}
	if (z1 > z2)
	{
		dwnleft.setValueZ(z2);
		upright2.setValueZ(z1);
		z1 = dwnleft.getValueZ();
		z2 = upright2.getValueZ();
	}
	dwnleft2.setValueX(x1);
	dwnleft2.setValueY(y1);
	dwnleft2.setValueZ(z2);

	dwnright2.setValueX(x2);
	dwnright2.setValueY(y1);
	dwnright2.setValueZ(z2);

	dwnright.setValueX(x2);
	dwnright.setValueY(y1);
	dwnright.setValueZ(z1);

	upright.setValueX(x2);
	upright.setValueY(y2);
	upright.setValueZ(z1);

	upleft.setValueX(x1);
	upleft.setValueY(y2);
	upleft.setValueZ(z1);

	upleft2.setValueX(x1);
	upleft2.setValueY(y2);
	upleft2.setValueZ(z2);
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