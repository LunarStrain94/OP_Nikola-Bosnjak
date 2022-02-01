#ifndef _ANIMAL
#define _ANIMAL
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
public:
	virtual int getLegs() = 0;
	virtual string getSpecies() = 0;
	virtual ~Animal() = 0;
};



class Insect : public Animal {
public:
	Insect() {};
};

class Mosquito : public Insect {
private:
	int legs;
	string species;
public:
	Mosquito();
	int getLegs();
	string getSpecies();
	~Mosquito();
};

class Cockroach : public Insect {
private:
	int legs;
	string species;
public:
	Cockroach();
	int getLegs();
	string getSpecies();
	~Cockroach();
};



class Bird : public Animal {
public:
	Bird() {};
};

class Eagle : public Bird {
private:
	int legs;
	string species;
public:
	Eagle();
	int getLegs();
	string getSpecies();
	~Eagle();
};

class Parrot : public Bird {
private:
	int legs;
	string species;
public:
	Parrot();
	int getLegs();
	string getSpecies();
	~Parrot();
};



class Spider : public Animal {
public:
	Spider() {};
};

class Tarantula : public Spider {
private:
	int legs;
	string species;
public:
	Tarantula();
	int getLegs();
	string getSpecies();
	~Tarantula();
};

class BlackWidow : public Spider {
private:
	int legs;
	string species;
public:
	BlackWidow();
	int getLegs();
	string getSpecies();
	~BlackWidow();
};


#endif