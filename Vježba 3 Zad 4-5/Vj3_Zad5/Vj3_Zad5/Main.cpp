#include <iostream>
#include <string>
#include "Header.hpp"
using namespace std;

int main()
{
	string str = "Buffalo buffalo Buffalo buffalo buffalo buffalo Buffalo buffalo";
	string str2 = "Buffalo";
	string str3 = "buffalo";
	int n = countStr(str, str2);
	cout << n;
}