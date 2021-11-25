#include <iostream>
#include <vector>
#include "Header.hpp"
using namespace std;

int main()
{
	int n, el;
	vector<int> v1;

	cout << "Input the number of vector elements: ";
	cin >> n;
	inputVec(v1, n);
	printVec(v1);
	cout << endl;

	cout << "What element do you want to remove: ";
	cin >> el;
	removeVecEl(v1, el);
	printVec(v1);
}
