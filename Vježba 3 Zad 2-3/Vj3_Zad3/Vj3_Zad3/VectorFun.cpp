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

void inputVec2(vector<int>& v, int a, int b)
{
	int t, input;
	if (b < a)
	{
		t = b;
		b = a;
		a = t;
	}
	for (;;)
	{
		cout << ">>";
		cin >> input;
		if (input < a || input > b)
			break;
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

bool cmp(int i, int j)
{
	return (i > j);
}

void fun(vector<int>& v)
{
	int min = v[0], ind = 0, n = v.size(), sum = 0;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		if (v[i] < min)
		{
			ind = i;
			min = v[i];
		}
	}
	v.insert(v.begin()+ind, 0);
	v.push_back(sum);
}