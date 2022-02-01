#include "Game.hpp"

bool Game::isGameOver(vector<HumanPlayer>& pl, vector<ComputerPlayer>& cpu) {
	for (int i = 0; i < npl; ++i) {
		if (pl[i].getScore() >= goal)
			return true;
	}
	for (int i = 0; i < ncpu; ++i) {
		if (cpu[i].getScore() >= goal)
			return true;
	}
	return false;
}

void Game::winner(vector<HumanPlayer>& pl, vector<ComputerPlayer>& cpu) {
	int max = 0, ind;
	for (int i = 0; i < npl; ++i) {
		if (pl[i].getScore() > max) {
			max = pl[i].getScore();
			ind = i;
		}
	}
	for (int i = 0; i < ncpu; ++i) {
		if (cpu[i].getScore() > max) {
			max = cpu[i].getScore();
			ind = i + npl;
		}
	}
	system("cls");
	cout << "Player " << ind + 1 << " won!";
}

void Game::round(vector<HumanPlayer>& pl, vector<ComputerPlayer>& cpu) {
	int hand1, guess1; 
	for (int i = 0; i < npl; ++i) {
		pl[i].chooseHand(i);
	}
	for (int i = 0; i < ncpu; ++i) {
		cpu[i].generateHand(i + npl);
	}
	for (int i = 0; i < npl; ++i) {
		pl[i].guessHand(i);
		guess1 = pl[i].getGuess();
		for (int j = 0; j < npl; ++j) {
			if (j == i)
				continue;
			hand1 = pl[j].getHand();
			if (guess1 == hand1)
				pl[i].incrScore();
		}
		for (int j = 0; j < ncpu; ++j) {
			hand1 = cpu[j].getHand();
			if (guess1 == hand1)
				pl[i].incrScore();
		}
	}
	for (int i = 0; i < ncpu; ++i) {
		cpu[i].generateGuess(i + npl);
		guess1 = cpu[i].getGuess();
		for (int j = 0; j < npl; ++j) {
			hand1 = pl[j].getHand();
			if (guess1 == hand1)
				cpu[i].incrScore();
		}
		for (int j = 0; j < ncpu; ++j) {
			if (j == i)
				continue;
			hand1 = cpu[j].getHand();
			if (guess1 == hand1)
				cpu[i].incrScore();
		}
	}
	for (int i = 0; i < npl; ++i) {
		pl[i].setGuess(0);
		pl[i].setHand(0);
	}
}

void Game::scoreboard(vector<HumanPlayer>& pl, vector<ComputerPlayer>& cpu) {
	system("cls");
	int score1, total = ncpu + npl;
	for (int i = 0; i < npl; ++i) {
		score1 = pl[i].getScore();
		cout << "P" << i + 1 << " " << score1 << "/" << goal << endl;
	}
	for (int i = 0; i < ncpu; ++i) {
		score1 = cpu[i].getScore();
		cout << "P" << npl + i + 1 << " " << score1 << "/" << goal << endl;
	}
	Sleep(2000);
}

//__________________________________  _______________\¡/_______                                 
//|______  __|  \_  ___   /  \__    \ |  |  _____|____¡ _|     \            
//      |  |  /\ \_ |__> / /\ \__    \|  |  |_____   / / |  |\  \            
//      |  | |__| \   __/ |__| \   \     |  _____|  / /  |  |_\  \       
//      |  | ____ |  |  | ____ |   |\    |  |____ _/ /___|  ___   |      
//___   |  |_|  |_|__|  |_|  |_|___| \___|_______|_______|__| |   |  
//\  \_/   /                                                   \  |       
// \______/                                                     \_|       
//