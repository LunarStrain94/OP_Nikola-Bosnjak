#include "Header.hpp"

int main()
{
	srand(time(NULL));
	Point a1;
	Gun gun;
	double min1 = -10, max1 = 10, angle;
	int n, n2, cnt = 0;
	
	cout << "Enter the number of targets: ";
	cin >> n;
	Target* tarArr = new Target[n];
	cout << "Enter the number of shots: ";
	cin >> n2;
	gun.setMagsize(n2);

	for (int i = 0; i < n; ++i)
		tarArr[i].generateTar(min1, max1);

	for (int i = 0; i < n; ++i)
	{
		if (tarArr[i].update(gun) == true)
		{
			++cnt;
			gun.shoot();
			//cout << i << " ";
		}
	}

	cout << cnt << " targets were shot";
}