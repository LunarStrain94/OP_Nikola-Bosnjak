#include "Player.hpp"

int Player::getHand() {
	return hand;
}

int Player::getGuess() {
	return guess;
}

int Player::getScore() {
	return score;
}

void Player::setScore(int a) {
	score = a;
}

void Player::setHand(int a) {
	hand = a;
}

void Player::setGuess(int a) {
	guess = a;
}

void Player::incrScore() {
	score++;
}

void HumanPlayer::chooseHand(int a) {
	int input, state = 0;
	int arr[3] = { 1, 2, 5 };
	int set[3] = { 0, 0, 0 };
	while (true) {
		system("cls");
		cout << "Player " << a + 1;
		cout << "\n\nChoose your hand:\n\n     .---.         .---.         .---." << endl << "    /     \\       /     \\       /     \\" << endl;
		cout << "   |  1 kn |     |  2 kn |     |  5 kn |" << endl << "    \\     /       \\     /       \\     /" << endl;
		cout << "     '---'         '---'         '---'" << endl << endl;
		if (hand == 1 || hand == 3 || hand == 6 || hand == 8)
			cout << "     ( O )";
		else 
			cout << "     (   )";
		if (hand == 2 || hand == 3 || hand == 7 || hand == 8)
			cout << "         ( O )";
		else
			cout << "         (   )";
		if (hand == 5 || hand == 6 || hand == 7 || hand == 8)
			cout << "         ( O )" << endl;
		else
			cout << "         (   )" << endl;

		if (state == 0)
			cout << "      /-\\";
		else if (state == 1)
			cout << "                    /-\\";
		else
			cout << "                                  /-\\";
		cout << "\n\n\n ____ ____\n |<-| |->| -move\n '''' ''''\n _________\n | space | - change\n '''''''''\n _________\n |       |\n | enter | - confirm\n |___    |\n    |    |\n    |____|";

		input = _getch();
		if (input == KEY_LEFT && state > 0)
			state--;
		if (input == KEY_RIGHT && state < 2)
			state++;
		if (input == ' ') {
			if (set[state] == 0) {
				hand += arr[state];
				set[state] = 1;
			}
			else {
				hand -= arr[state];
				set[state] = 0;
			}
		}
		if (input == '\r')
			return;
	}
}

//     .---.         .---.         .---.
//   /'     '\     /'     '\     /'     '\
//  |   1 kn  |   |   2 kn  |   |   5 kn  |
//   \.     ./     \.     ./     \.     ./
//     '---'         '---'         '---'
//
//     (   )         (   )         (   )
//
// all - 0 1 2 3 5 6 7 8 
//  1  - 1 3 6 8
//  2  - 2 3 7 8
//  5  - 5 6 7 8
// 
// _________
// |       |
// | enter | - confirm
// |___    |
//    |    |
//    |____|

void HumanPlayer::guessHand(int a) {
	int input, state = 0;
	int arr[8] = { 0, 1, 2, 3, 5, 6, 7, 8 };
	while (true) {
		system("cls");
		cout << "Player " << a + 1 << "\n\nGuess your opponents' hands:\n" << "0 1 2 3 5 6 7 8" << endl;
		for (int i = 0; i < state; ++i)
			cout << "  ";
		cout << "A";
		input = _getch();
		if (input == KEY_LEFT && state > 0)
			state--;
		if (input == KEY_RIGHT && state < 7)
			state++;
		if (input == ' ' || input == '\r') {
			guess = arr[state];
			return;
		}
	}
}

void ComputerPlayer::generateHand(int a) {
	system("cls");
	cout << "Player " << a + 1 << " is choosing...";
	Sleep(110);
	int members[8] = { 0, 1, 2, 3, 5, 6, 7, 8 };
	hand = members[rand() % 7];
}

void ComputerPlayer::generateGuess(int a) {
	system("cls");
	Sleep(110);
	cout << "Player " << a + 1 << " is choosing...";
	int members[8] = { 0, 1, 2, 3, 5, 6, 7, 8 };
	guess = members[rand() % 7];
}