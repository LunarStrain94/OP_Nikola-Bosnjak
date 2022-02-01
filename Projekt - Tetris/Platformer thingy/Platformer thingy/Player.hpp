#ifndef _PLAY
#define _PLAY
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point() : x(0), y(0) {}
	Point(int x1, int y1) : x(x1), y(y1) {}
	Point(const Point& other) : x(other.x), y(other.y) {}
	int getX();
	int getY();
	void setX(int a);
	void setY(int a);
};

class Player {
private:
	Point pos;
	int id, rot;
	string str;
public:
	Player()
	{
		rot = 0;
		setXpos(5);
		setYpos(18);
	}
	int getID();
	int getXpos();
	int getYpos();
	int getRot();
	string getStr();
	void setID(int a);
	void incRot();
	void decRot();
	void setStr();
	void setXpos(int a);
	void setYpos(int a);
};

#endif