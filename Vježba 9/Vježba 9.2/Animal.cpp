#include "Animal.hpp"

Animal::~Animal() {}



Mosquito::Mosquito() {
	legs = 6;
	species = "Mosquito";
}
int Mosquito::getLegs() {
	return legs;
}
string Mosquito::getSpecies() {
	return species;
}
Mosquito::~Mosquito() {
	legs = 0;
	species = "";
}



Cockroach::Cockroach() {
	legs = 6;
	species = "Cockroach";
}
int Cockroach::getLegs() {
	return legs;
}
string Cockroach::getSpecies() {
	return species;
}
Cockroach::~Cockroach() {
	legs = 0;
	species = "";
}



Eagle::Eagle() {
	legs = 2;
	species = "Eagle";
}
int Eagle::getLegs() {
	return legs;
}
string Eagle::getSpecies() {
	return species;
}
Eagle::~Eagle() {
	legs = 0;
	species = "";
}



Parrot::Parrot() {
	legs = 2;
	species = "Parrot";
}
int Parrot::getLegs() {
	return legs;
}
string Parrot::getSpecies() {
	return species;
}
Parrot::~Parrot() {
	legs = 0;
	species = "";
}



Tarantula::Tarantula() {
	legs = 8;
	species = "Tarantula";
}
int Tarantula::getLegs() {
	return legs;
}
string Tarantula::getSpecies() {
	return species;
}
Tarantula::~Tarantula() {
	legs = 0;
	species = "";
}



BlackWidow::BlackWidow() {
	legs = 8;
	species = "Black Widow";
}
int BlackWidow::getLegs() {
	return legs;
}
string BlackWidow::getSpecies() {
	return species;
}
BlackWidow::~BlackWidow() {
	legs = 0;
	species = "";
}