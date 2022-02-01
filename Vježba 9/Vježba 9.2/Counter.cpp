#include "Counter.hpp"

void Counter::getSum(vector<Animal*>& a){
	int len = a.size();
	for (int i = 0; i < len; ++i) {
		cout << "Animal added: " << a[i]->getSpecies() << endl;
		sum += a[i]->getLegs();
	}
}

void Counter::printSum() {
	cout << "Sum of legs: " << sum << endl;
}