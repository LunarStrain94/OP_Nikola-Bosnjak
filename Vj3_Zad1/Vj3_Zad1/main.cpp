#include <iostream>
#include <vector>
#include "Header.hpp"
using namespace std;

int main()
{
	int n, a, b;
	vector<int> v1;
	vector<int> v2;

	cout << "Input the number of vector elements: ";
	cin >> n;
	inputVec(v1, n);
	printVec(v1);
	cout << endl;

	cout << "Input the range of vector elements: \n-a: ";
	cin >> a;
	cout << "-b: ";
	cin >> b;
	cout << endl;
	inputVec2(v2, a, b);
	printVec(v2);
}
