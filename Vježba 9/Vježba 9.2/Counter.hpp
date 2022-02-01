#ifndef _COUNTER
#define _COUNTER
#include "Animal.hpp"

class Counter {
private:
	int sum = 0;
public:
	void getSum(vector<Animal*>& a);
	void printSum();
};

#endif