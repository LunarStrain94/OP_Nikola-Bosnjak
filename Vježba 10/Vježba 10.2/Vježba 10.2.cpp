#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
public:
	vector<T> arr;
	void push(const T& n);
	void print();
	void pop();
	bool isEmpty();
};

template <typename T>
void Stack<T>::push(const T& n) {
	arr.push_back(n);
}

template <typename T>
void Stack<T>::pop() {
	arr.pop_back();
}

template <typename T>
void Stack<T>::print() {
	int len = arr.size();
	for (int i = 0; i < len; ++i)
		cout << arr[i] << " ";
}

template <typename T>
bool Stack<T>::isEmpty() {
	return arr.size();
}

/*template <>
void Stack<char>::print() {
	int len = arr.length();
	for (int i = 0; i < len; ++i)
		cout << arr[i];
}*/

void main() {
	Stack<int> arr;
	arr.push(1);
	arr.push(2);
	arr.push(3);
	arr.push(4);
	arr.pop();
	arr.print();
}