#include "Game.hpp"

void goToZero() {
	COORD c;
	c.X = 0;
	c.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Game::options() {
	int c = 0, i = 0;
	while (true) {
		system("cls");
		if (i == 0) {
			cout << ">Starting level: " << speed;
			cout << "\n Back to Main Menu";
		}
		else if (i == 1) {
			cout << " Starting level: " << speed;
			cout << "\n>Back to Main Menu";
		}

		if (_kbhit())
			c = _getch();
		else
			c = 0;
		if (c == '\r' && i == 0) {
			system("cls");
			++speed;
			if (speed > 9)
				speed = 0;
		}
		else if ((c == 's' && i == 1) || (c == 'S' && i == 1)) {
			system("cls");
			++speed;
			if (speed > 9)
				speed = 0;
		}
		else if (c == '\r' && i == 1) {
			system("cls");
			return;
		}
		else if ((c == 's' && i == 1) || (c == 'S' && i == 1)) {
			system("cls");
			return;
		}
		else if (c == KEY_DOWN || c == KEY_UP) {
			if (i == 1)
				i = 0;
			else if (i == 0)
				i = 1;
		}
	}
}

int Game::mainMenu() {
	int c = 0, i = 0;
	while (true) {
		system("cls");
		cout << "\n  ______________________________________________ ____ __________";
		cout << "\n  |___    ___||   _______||___    ___||   ___   \\|  |/   ____   \\";
		cout << "\n  |XXX|  |XXX||  |XXXXXXX||XXX|  |XXX||  |XXX\\   |  |   /|XX|\\   |";
		cout << "\n  ''''|  |''''|  |''''''''''''|  |''''|  |'''/   |  |   \\''''\\|XX|";
		cout << "\n      |  |    |  ''''''''|    |  |    |  ''''   /|  |\\   '''''''\\'";
		cout << "\n      |  |    |  |XXXXXXX|    |  |    |  |X\\  \\'/|  |\\|XXXXXX\\   |";
		cout << "\n      |  |    |  |''''''''    |  |    |  |^\\\\  \\ |  |'''\\''''/   |";
		cout << "\n      |  |    |  ''''''''|    |  |    |  |  \\\\  \\|  |\\   ''''   /|";
		cout << "\n      |XX|    |XXXXXXXXXX|    |XX|    |XX|   \\|XX|XX|\\|XXXXXXXX|/";
		cout << "\n      ''''    ''''''''''''    ''''    ''''    ''''''' ''''''''''";

		if (i == 0) {
			cout << "\n\n\n                              ___________";
			cout << "\n                              |S T A R T|";
			cout << "\n                              '''''''''''";
			cout << "\n                             O P T I O N S";
			cout << "\n                                         ";
			cout << "\n                                E X I T   ";
		}
		else if (i == 1) {
			cout << "\n\n\n\n                               S T A R T";
			cout << "\n                            _______________";
			cout << "\n                            |O P T I O N S|";
			cout << "\n                            '''''''''''''''";
			cout << "\n                                E X I T   ";
		}
		else if (i == 2) {
			cout << "\n\n\n\n                               S T A R T";
			cout << "\n\n                             O P T I O N S";
			cout << "\n                               _________";
			cout << "\n                               |E X I T|  ";
			cout << "\n                               '''''''''";
		}
		if (_kbhit())
			c = _getch();
		else
			c = 0;
		if (c == '\r' && i == 0) {
			system("cls");
			return 1;
		}
		else if (c == '\r' && i == 1) {
			system("cls");
			options();
		}
		else if ((c == 's' && i == 1) || (c == 'S' && i == 1)) {
			system("cls");
			options();
		}
		else if (c == '\r' && i == 2) {
			system("cls");
			return 0;
		}
		else if ((c == 's' && i == 2) || (c == 'S' && i == 2)) {
			goToZero();
			return 0;
		}
		else if (c == KEY_UP) {
			if (i == 0)
				i = 2;
			else
				--i;
		}
		else if (c == KEY_DOWN) {
			if (i == 2)
				i = 0;
			else
				++i;
		}
	}
}

// __________________________________________________ _______ __________
// |           ||           ||           ||          \|     |/          \
// |XXX|   |XXX||   |XXXXXXX||XXX|   |XXX||   |XXX\   |     |   /|XX|\   |
// ''''|   |''''|   |''''''''''''|   |''''|   |'''/   |     |   \''''\|XX|
//     |   |    |   ''''''''|    |   |    |   ''''   /|     |\   '''''''\'
//     |   |    |   |XXXXXXX|    |   |    |   |X\  \'/|     |\|XXXXXX\   |
//     |   |    |   |''''''''    |   |    |   |^\\  \ |     ||''\''''/   |
//     |   |    |   ''''''''|    |   |    |   |  \\  \|     |\   ''''   /|
//     |XXX|    |XXXXXXXXXXX|    |XXX|    |XXX|   \|XX|XXXXX|\|XXXXXXXX|/
//     '''''    '''''''''''''    '''''    '''''    '''''''''' ''''''''''

// __________________________________________________ _______ __________
// |           ||           ||           ||          \|     |/   ____   \
// """"|   |""""|   |""""""""""""|   |""""|   |"""\   |     |   /    \__|
//     |   |    |   |________    |   |    |   |___/   |     |   \_______
//     |   |    |           |    |   |    |          /|     |\          \
//     |   |    |   |""""""""    |   |    |   |"\  \" |     | """""""\   |
//     |   |    |   |________    |   |    |   |  \  \ |     ||""\____/   |
//     |   |    |           |    |   |    |   |   \  \|     |\          /
//     """""    """""""""""""    """""    """""    """""""""" """"""""""

void Game::display() {
	string str;
	for (int i = height - 1; i >= 0; --i)
	{
		cout << "   ";
		for (int j = 0; j < length; ++j) {
			if (brd[i][j] == '0')
				cout << "[]";
			else if (brd[i][j] == '|')
				cout << "||";
			else
				cout << brd[i][j] << brd[i][j];
		}
		cout << endl;
	}

	cout << "   Level: " << speed << "   Score: " << score;
	if (next == 0)// 0
		str = "0\n0\n0\n0";
	else if (next == 1)// 1
		str = " 0 \n000";
	else if (next == 2)// 2
		str = " 0\n00\n0 ";
	else if (next == 3)// 3
		str = "0 \n00\n 0";
	else if (next == 4)// 4
		str = "00\n00";
	else if (next == 5)// 5
		str = "0 \n0 \n00";
	else if (next == 6)// 6
		str = " 0\n 0\n00";

	int k = 0;
	for (int i = 0; i < 6; ++i)
	{
		cout << endl << "         ";
		for (int j = 0; j < 12; ++j) {
			if (i == 0) {
				if (j == 11)
					continue;
				cout << "_";
			}
			else if (i == 5) {
				if (j == 11)
					continue;
				cout << '"';
			}
			else if (j == 0 || j == 11)
				cout << "|";
			else if (j == 1 || j == 10)
				cout << " ";
			else if (str[k] == '0') {
				cout << "[]";
				++j;
				++k;
			}
			else if (str[k] == ' ') {
				cout << "  ";
				++j;
				++k;
			}
			else if (str[k] == '\n' || str[k] == '\0') {
				while (j < 10) {
					++j;
					cout << " ";
				}
				if (str[k] == '\n')
					++k;
			}
		}
	}
}

//
// NEXT:
// ____________
// | []       |
// | []       |
// | []       |
// | [][][][] |
// ''''''''''''
//

void Game::clearRow(int row) {
	for (int i = row; i < height - 2; ++i) {
		for (int j = 0; j < length; ++j)
			brd[i][j] = brd[i + 1][j];
	}
}

void Game::updateGame() {
	int add = 0;
	for (int i = 1; i < height - 1; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < length; ++j)
		{
			if (brd[i][j] == '0' || brd[i][j] == '|')
				++cnt;
			if (cnt == length) {
				clearRow(i);
				++add;
				--i;
			}
		}
	}
	if (add == 1)
		score += 40 * (speed + 1);
	else if (add == 2)
		score += 100 * (speed + 1);
	else if (add == 3)
		score += 300 * (speed + 1);
	else if (add == 4)
		score += 1200 * (speed + 1);
	lines += add;
	if (lines >= (speed + 1) * 10) {
		++speed;
		frame = 0;
	}
}

void Game::initPlayer(Player& pl) {
	pl.setXpos(length / 2 - 1);
	pl.setYpos(height - 2);
	pl.setID(next);
	next = rand() % 7;
	pl.setStr();
	int posX = pl.getXpos(), posY = pl.getYpos(), start = pl.getXpos();
	string str = pl.getStr();
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '0') {
			brd[posY][posX] = '0';
			++posX;
		}
		else if (str[i] == ' ')
			++posX;
		else if (str[i] == '\n') {
			posX = start;
			--posY;
		}
	}
}

void Game::drawPlayer(Player& pl, int posX1, int posY1) {
	string str = pl.getStr();
	int posX = pl.getXpos(), posY = pl.getYpos();
	int start = posX;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '0') {
			brd[posY][posX] = ' ';
			++posX;
		}
		else if (str[i] == ' ')
			++posX;
		else if (str[i] == '\n') {
			posX = start;
			--posY;
		}
	}

	start = posX1;
	pl.setXpos(posX1);
	pl.setYpos(posY1);
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '0') {
			brd[posY1][posX1] = '0';
			++posX1;
		}
		else if (str[i] == ' ')
			++posX1;
		else if (str[i] == '\n') {
			posX1 = start;
			--posY1;
		}
	}
}

bool Game::checkPlayer(Player& pl, int input) {
	int posX = pl.getXpos(), posY = pl.getYpos();
	int start = posX, addY = 0, addX = 0;
	string str = pl.getStr();
	bool can = true;

	if (input == KEY_DOWN)
		addY = -1;
	else if (input == KEY_LEFT)
		addX = -1;
	else if (input == KEY_RIGHT)
		addX = 1;

	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '0') {
			brd[posY][posX] = ' ';
			++posX;
		}
		else if (str[i] == ' ')
			++posX;
		else if (str[i] == '\n') {
			posX = start;
			--posY;
		}
	}

	posX = pl.getXpos();
	posY = pl.getYpos();
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '\n') {
			posX = start;
			--posY;
		}
		else if (str[i] == '0') {
			if (brd[posY + addY][posX + addX] != ' ') {
				can = false;
				break;
			}
			++posX;
		}
		else if (str[i] == ' ')
			++posX;
	}

	posX = pl.getXpos();
	posY = pl.getYpos();
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '0') {
			brd[posY][posX] = '0';
			++posX;
		}
		else if (str[i] == ' ')
			++posX;
		else if (str[i] == '\n') {
			posX = start;
			--posY;
		}
	}
	return can;
}

void Game::rotPlayer(Player& pl, int add) {
	bool can = true;
	string str = pl.getStr();
	int posX = pl.getXpos(), posY = pl.getYpos();
	int start = posX;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '0') {
			brd[posY][posX] = ' ';
			++posX;
		}
		else if (str[i] == ' ')
			++posX;
		else if (str[i] == '\n') {
			posX = start;
			--posY;
		}
	}

	if (add == 1)
		pl.incRot();
	else if (add == -1)
		pl.decRot();
	pl.setStr();
	str = pl.getStr();
	posX = pl.getXpos();
	posY = pl.getYpos();
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '\n') {
			posX = start;
			--posY;
		}
		else if (str[i] == '0') {
			if (brd[posY][posX] != ' ') {
				can = false;
				break;
			}
			++posX;
		}
		else if (str[i] == ' ')
			++posX;
	}

	if (can == false) {
		if (add == 1)
			pl.decRot();
		if (add == -1)
			pl.incRot();
		pl.setStr();
		str = pl.getStr();
	}
	posX = pl.getXpos();
	posY = pl.getYpos();
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '0') {
			brd[posY][posX] = ' ';
			++posX;
		}
		else if (str[i] == ' ')
			++posX;
		else if (str[i] == '\n') {
			posX = start;
			--posY;
		}
	}
}

void Game::updatePlayer(Player& pl, int input) {
	bool stuck = false;
	int posX = pl.getXpos();
	int posY = pl.getYpos();

	if (input == KEY_DOWN) {
		if (checkPlayer(pl, input))
			drawPlayer(pl, posX, posY - 1);
	}
	else if (input == KEY_LEFT) {
		if (checkPlayer(pl, input))
			drawPlayer(pl, posX - 1, posY);
	}
	else if (input == KEY_RIGHT) {
		if (checkPlayer(pl, input))
			drawPlayer(pl, posX + 1, posY);
	}
	else if (input == 'a' || input == 'A') {
		rotPlayer(pl, -1);
	}
	else if (input == 's' || input == 'S')
		rotPlayer(pl, 1);
	else if (input == '\r') {
		while (true) {
			input = 0;
			if (_kbhit())
				input = _getch();
			if (input == '\r')
				break;
		}
	}

	if (speed > 13 || input == KEY_DOWN) {
		if (checkPlayer(pl, KEY_DOWN))
			drawPlayer(pl, pl.getXpos(), pl.getYpos() - 1);
		else {
			updateGame();
			initPlayer(pl);
		}
	}
	else if (frame % (14 - speed) == 0 || input == KEY_DOWN) {
		if (checkPlayer(pl, KEY_DOWN))
			drawPlayer(pl, pl.getXpos(), pl.getYpos() - 1);
		else {
			updateGame();
			initPlayer(pl);
		}
	}
	++frame;
}