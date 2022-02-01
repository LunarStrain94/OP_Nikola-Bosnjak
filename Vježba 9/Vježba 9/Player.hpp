#define KEY_LEFT 75
#define KEY_RIGHT 77
#ifndef _PLAYER
#define _PLAYER
#include <iostream>
#include <conio.h>
#include <time.h>
#include <vector>
#include <Windows.h>
using namespace std;

class Player {
protected:
	int hand, guess, score;
public:
	Player() {
		hand = 0;
		guess = 0;
		score = 0;
	}
	int getHand();
	int getGuess();
	int getScore();
	void setHand(int a);
	void setGuess(int a);
	void setScore(int a);
	void incrScore();
};

class HumanPlayer : public Player {
private:
public:
	void chooseHand(int a);
	void guessHand(int a);
};

class ComputerPlayer : public Player {
private:
public:
	void generateHand(int a);
	void generateGuess(int a);
};

#endif
