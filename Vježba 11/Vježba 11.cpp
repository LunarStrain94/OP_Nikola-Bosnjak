#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

bool isBigger(int i) { return i > 500;}

bool isSmaller(int i) { return i < 300; }

void fun(string name, vector<int>& v1) {
	try {
		ifstream fin(name);
		istream_iterator<string> it(fin);
		istream_iterator<string> eos;
		vector<string> v;
		copy(it, eos, back_inserter(v));

		if (!fin.is_open())
			throw exception();

		vector<int> num;
		int len = v.size();
		for (int i = 0; i < len; i++) {
			int temp = 0;
			stringstream strint(v[i]);
			strint >> temp;
			num.push_back(temp);
		}
		int cnt = count_if(num.begin(), num.end(), isBigger);
		cout << "Numbers over 500: " << cnt << endl;

		int max = *max_element(num.begin(), num.end());
		cout << "Max value: " << max << endl;

		int min = *min_element(num.begin(), num.end());
		cout << "Min value: " << min << endl;

		num.erase(remove_if(num.begin(), num.end(), isSmaller), num.end());

		sort(num.begin(), num.end(), greater<int>());
		v1 = num;
	}
	catch (exception& e) {
		cerr << "File not found\n";
	}
}

int main() {
	vector<int> v;
	vector<int> v1;
	fun("numers.txt", v1);
	fun("numbers.txt", v);
	int len = v.size();
	for (int i = 0; i < len; i++)
		cout << v[i] << " ";
}