#ifndef _FUN
#define _FUN
#include "Player.hpp"

void goToZero();

class Game {
private:
	int height, length, speed, score, frame, lines, next;
	char** brd;
public:
	Game()
	{
		next = rand() % 7;
		height = 10;
		length = 20;
		score = 0;
		speed = 0;
		frame = 0;
		lines = 0;

		brd = new char* [height];
		for (int i = 0; i < height; i++)
			brd[i] = new char[length];
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (i == 0 || i == (height - 1))
					brd[i][j] = '_';
				else if (j == 0 || j == (length - 1))
					brd[i][j] = '|';
				else
					brd[i][j] = ' ';
			}
		}
	}
	Game(int m, int n)
	{
		next = rand() % 7;
		height = n;
		length = m;
		score = 0;
		speed = 0;
		frame = 0;
		lines = 0;

		brd = new char* [height];
		for (int i = 0; i < height; i++)
			brd[i] = new char[length];
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (i == (height - 1))
					brd[i][j] = '_';
				else if (i == 0)
					brd[i][j] = '"';
				else if (j == 0 || j == (length - 1))
					brd[i][j] = '|';
				else
					brd[i][j] = ' ';
			}
		}
	}
	Game(const Game& other)
	{
		height = other.height;
		length = other.length;
		brd = new char* [height];
		for (int i = 0; i < height; i++)
			brd[i] = new char[length];
		memcpy(brd, other.brd, length * sizeof(height));
	}
	Game(Game&& other)
	{
		height = other.height;
		length = other.length;
		brd = other.brd;

		other.height = 0;
		other.length = 0;
		other.brd = nullptr;
	}
	~Game()
	{
		height = 0;
		length = 0;
		for (int i = 0; i < height; i++)
			delete[] brd[i];
		delete[] brd;
	}

	void options();
	int mainMenu();
	void initPlayer(Player& pl);
	void drawPlayer(Player& pl, int posX1, int posY1);
	void rotPlayer(Player& pl, int add);
	bool checkPlayer(Player& pl, int input);
	void updateGame();
	void clearRow(int row);
	void updatePlayer(Player& pl, int input);
	void display();
};

#endif