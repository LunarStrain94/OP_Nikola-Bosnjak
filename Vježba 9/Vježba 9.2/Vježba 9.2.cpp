#include "Counter.hpp"

int main() {
	vector<Animal*> animal;
	Counter counter;

	animal.push_back(new Mosquito);
	animal.push_back(new Eagle);
	animal.push_back(new Tarantula);

	counter.getSum(animal);
	counter.printSum();
}