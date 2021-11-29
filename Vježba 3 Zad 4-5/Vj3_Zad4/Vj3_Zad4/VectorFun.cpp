#include "Header.hpp"

using namespace std;

void inputVec(vector<int>& v, int n)
{
	int input;
	for (int i = 0; i < n; ++i)
	{
		cout << ">>";
		cin >> input;
		v.push_back(input);
	}
}

void printVec(vector<int> v)
{
	cout << endl;
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
}

void removeVecEl(vector<int>& v, int el)
{
	vector<int>::iterator it = find(v.begin(), v.end(), el);
	if (it != v.end())
	{
		*it = v.back();
		v.pop_back();
	}
	else
		cout << "Element not found in vector" << endl;
}