#include <iostream>
#include <algorithm>
#include <vector>
#include "Header.hpp"
using namespace std;

int main()
{
	int n;
	vector<int> v1;

	cout << "Input the number of vector elements: ";
	cin >> n;
	inputVec(v1, n);
	printVec(v1);
	cout << endl;

	fun(v1);
	printVec(v1);
}
