#include "Header.hpp"

void inputVec(vector<int>& v)
{
	int input;
	for (;;)
	{
		cout << ">>";
		cin >> input;
		if (input != 0 && input != 1)
			return;
		v.push_back(input);
	}
}

void stuffingBit(vector<int>& v)
{
	int n = v.size(), c = 0, add = 0;
	int* arr;
	for (int i = 1; i < n; i++)
	{
		if (v[i] == 1 && v[i - 1] == 1)
			++c;
		else
			c = 0;
		if (c == 4)
		{
			++add;
			c = 0;
		}
	}
	arr = new int[n + add];
	arr[0] = v[0];
	c = 0;
	for (int i = 1, j = 1; i < n; i++)
	{
		if (v[i] == 1 && v[i - 1] == 1)
			++c;
		else
			c = 0;
		if (c == 4)
		{
			arr[j] = v[i];
			++j;
			arr[j] = 0;
			++j;
			v[i] = 0;
			c = 0;
		}
		else
		{
			arr[j] = v[i];
			++j;
		}
	}
	v.clear();
	n += add;
	for (int i = 0; i < n; i++)
		v.push_back(arr[i]);
	delete[] arr;
}

void unstuffingBit(vector<int>& v)
{
	int n = v.size(), c = 0, add = 0;
	int* arr;
	for (int i = 1, j = 1; i < n; i++)
	{
		if (v[i] == 1 && v[i - 1] == 1)
			++c;
		else
			c = 0;
		if (c == 4 && v[i + 1] == 0)
		{
			++add;
			c = 0;
		}
	}
	arr = new int[n - add];
	arr[0] = v[0];
	c = 0;
	for (int i = 1, j = 1; i < n; i++)
	{
		if (v[i] == 1 && v[i - 1] == 1)
			++c;
		else
			c = 0;
		if (c == 4 && v[i + 1] == 0)
		{
			arr[j] = v[i];
			++j;
			++i;
			c = 0;
		}
		else
		{
			arr[j] = v[i];
			++j;
		}
	}
	v.clear();
	n -= add;
	for (int i = 0; i < n; i++)
		v.push_back(arr[i]);
	delete[] arr;
}

void printVec(vector<int> v)
{
	cout << endl;
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[i];
	cout << endl;
}