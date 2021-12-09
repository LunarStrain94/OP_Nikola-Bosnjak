#include "Header.hpp"

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

void Board::draw_char(Point p1, char ch)
{
	int x1 = (int)round(p1.getX());
	int y1 = (int)round(p1.getY());
	brd[y1][x1] = ch;
}


void Board::draw_up_line(Point p1, char ch)
{
	int x1 = (int)round(p1.getX());
	int y1 = (int)round(p1.getY());
	for (int i = 0; i <= y1; ++i)
		brd[i][x1] = ch;
}

void Board::draw_line(Point p1, Point p2, char ch)
{
	int x1 = (int)round(p1.getX());
	int y1 = (int)round(p1.getY());
	int x2 = (int)round(p2.getX());
	int y2 = (int)round(p2.getY());
	
	if (x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	if (x1 == x2 && y1 == y2)
	{
		brd[x1][y1] = ch;
	}
	while (x1 != x2 || y1 != y2)
	{
		int m = abs(y2 - abs(y2 - y1));
		int n = abs(x2 - abs(x2 - x1));

		brd[m][n] = ch;

		if (x1 != x2 && y1 != y2)
			x1++, y1++;
		else if (x1 == x2 && y1 != y2)
			y1++;
		else if (x1 != x2 && y1 == y2)
			x1++;
	}
}

void Board::display()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << brd[i][j];
		}
		cout << endl;
	}
}