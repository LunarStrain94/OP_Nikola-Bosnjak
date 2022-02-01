#ifndef _GAME
#define _GAME
#include "Player.hpp"

class Game {
private:
	int goal, npl, ncpu;
public:
	Game() {
		goal = 10;
	}
	Game(int goal1, int npl1, int ncpu1) {
		goal = goal1;
		npl = npl1;
		ncpu = ncpu1;
	}
	void round(vector<HumanPlayer>& pl, vector<ComputerPlayer>& cpu);
	void scoreboard(vector<HumanPlayer>& pl, vector<ComputerPlayer>& cpu);
	bool isGameOver(vector<HumanPlayer>& pl, vector<ComputerPlayer>& cpu);
	void winner(vector<HumanPlayer>& pl, vector<ComputerPlayer>& cpu);
};

#endif