#ifndef _FUN
#define _FUN
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

class Point {
private:	
	double x, y;
public:
	Point() : x(0), y(0) {}
	Point(double x1, double y1) : x(x1), y(y1) {}
	Point(const Point& other) : x(other.x), y(other.y) {}
	double getX();
	double getY();
};

class Board {
private:	
	int height, length;
	char** brd;
public:
	Board()
	{
		height = 10;
		length = 20;

		brd = new char* [height];
		for (int i = 0; i < height; i++)
			brd[i] = new char[length];
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (i == 0 || j == 0 || i == (height - 1) || j == (length - 1))
					brd[i][j] = 'o';
				else
					brd[i][j] = ' ';
			}
		}
	}
	Board(int m, int n)
	{
		height = n;
		length = m;

		brd = new char* [height];
		for (int i = 0; i < height; i++)
			brd[i] = new char[length];
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (i == 0 || j == 0 || i == (height - 1) || j == (length - 1))
					brd[i][j] = 'o';
				else
					brd[i][j] = ' ';
			}
		}
	}
	Board(const Board& other)
	{
		height = other.height;
		length = other.length;
		brd = new char* [height];
		for (int i = 0; i < height; i++)
			brd[i] = new char[length];
		memcpy(brd, other.brd, length * sizeof(height));
	}
	Board(Board&& other)
	{
		height = other.height;
		length = other.length;
		brd = other.brd;

		other.height = 0;
		other.length = 0;
		other.brd = nullptr;
	}
	~Board()
	{
		height = 0;
		length = 0;
		for (int i = 0; i < height; i++)
			delete[] brd[i];
		delete[] brd;
	}

	void draw_char(Point p1, char ch);
	void draw_up_line(Point p1, char ch);
	void draw_line(Point p1, Point p2, char ch);
	void display();
};

#endif