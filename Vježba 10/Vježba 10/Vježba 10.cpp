#include <iostream>
using namespace std;

template <typename T>
void sortArr(T arr[], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i] < arr[j])
				swap(arr[i], arr[j]);
		}
	}
}

template <>
void sortArr<char>(char arr[], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (tolower(arr[i]) < tolower(arr[j]))
				swap(arr[i], arr[j]);
		}
	}
}

int main() {
    int a1[10] = {5, 4, 1, 6, 9, 8, 7, 2, 3, 2};
    char s[15] = {'T', 'h', 'y', ' ', 'C', 'a', 't', 'a', 'f', 'a', 'l', 'q', 'u', 'e'};
    for (int i = 0; i < 10; ++i)
        cout << a1[i] << " ";
    cout << s << endl;

    sortArr(a1, 10);
    sortArr(s, 14);
    for (int i = 0; i < 10; ++i)
        cout << a1[i] << " ";
	cout << s << endl;
}