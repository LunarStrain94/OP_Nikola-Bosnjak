#include "Header.hpp"

int main()
{
	srand(time(NULL));
	Point a1, a2;
	double x, y, z, x2, y2, z2;

	a1.setValueX(1);
	a1.setValueY(2);
	a1.setValueZ(3);
	x = a1.getValueX();
	y = a1.getValueY();
	z = a1.getValueZ();

	a1.setValueX(4);
	a1.setValueY(5);
	a1.setValueZ(6);
	x2 = a1.getValueX();
	y2 = a1.getValueY();
	z2 = a1.getValueZ();

	double dis2 = a1.distance2d(a1, a2);
	double dis3 = a1.distance3d(a1, a2);
	cout << dis2 << " " << dis3 << endl;
}