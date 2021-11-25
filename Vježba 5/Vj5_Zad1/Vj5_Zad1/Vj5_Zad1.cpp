#include "Header.hpp"

int main()
{
	srand(time(NULL));
	Point a1, a2;
	double x = 0, y = 0, z = 0, x2 = 0, y2 = 0, z2 = 0;

	a1.setValue(x, y, z);
	a1.getValue(x, y, z);
	a1.setValue(x2, y2, z2);
	a1.getValue(x2, y2, z2);

	double dis2 = a1.distance2d(a1, a2);
	double dis3 = a1.distance3d(a1, a2);
	cout << dis2 << " " << dis3 << endl;
}