#ifndef _FUN
#define _FUN
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void updateClock(int& hr, int& min, double& sec);

class timer {
private:
	int h, m;
	double s;
public:
	timer()
	{
		h = 0;
		m = 0;
		s = 0;
	}
	timer(int h1, int m1, double s1)
	{
		h = h1;
		m = m1;
		s = s1;
		updateClock(h, m, s);
	}
	timer(const timer& other)
	{
		h = other.h;
		m = other.m;
		s = other.s;
	}
	timer(timer&& other)
	{
		h = other.h;
		m = other.m;
		s = other.s;

		other.h = 0;
		other.m = 0;
		other.s = 0;
	}
	~timer()
	{
		h = 0;
		m = 0;
		s = 0;
	}



	timer operator=(const timer& other)
	{
		h = other.h;
		m = other.m;
		s = other.s;
		return other;
	}
	timer operator+=(const timer& other)
	{
		h = h + other.h;
		m = m + other.m;
		s = s + other.s;
		updateClock(h, m, s);
		return *this;
	}
	timer operator+(const timer& other)
	{
		h = h + other.h;
		m = m + other.m;
		s = s + other.s;
		updateClock(h, m, s);
		return *this;
	}
	timer operator-=(const timer& other)
	{
		m = 0;
		h = 0;
		s = (s + m * 60 + h * 3600) - (other.s + other.m * 60 + other.h * 3600);
		updateClock(h, m, s);
		return *this;
	}
	timer operator-(const timer& other)
	{
		s = (s + m * 60 + h * 3600) - (other.s + other.m * 60 + other.h * 3600);
		m = 0;
		h = 0;
		updateClock(h, m, s);
		return *this;
	}
	timer operator/=(int a)
	{
		s = (s + m * 60 + h * 3600) / a;
		m = 0;
		h = 0;
		updateClock(h, m, s);
		return *this;
	}
	timer operator/(int a)
	{
		s = (s + m * 60 + h * 3600) / a;
		m = 0;
		h = 0;
		updateClock(h, m, s);
		return *this;
	}
	friend bool operator<(const timer& other, const timer& other2)
	{
		timer t1;
		timer t2;
		t1.s = (other.s + other.m * 60 + other.h * 3600);
		t2.s = (other2.s + other2.m * 60 + other2.h * 3600);
		return (t1.s < t2.s);
	}
	friend ostream& operator<<(ostream& os, const timer& other)
	{
		os << other.h << ":" << other.m << ":" << other.s;
		return os;
	}
	operator double()
	{
		s += m * 60 + h * 360;
		return s;
	}
	


	int getHr();
	int getMin();
	double getSec();
	void setHr(int hr);
	void setMin(int min);
	void setSec(double sec);
};

class penalty {
private:
	int h, m;
	double s;
public:
	penalty(double s2)
	{
		h = 0;
		m = 0;
		s = s2;
		updateClock(h, m, s);
	}
	penalty operator()(timer& t)
	{
		int hr = t.getHr();
		int min = t.getMin();
		double sec = t.getSec() + s;
		updateClock(hr, min, sec);
		t.setHr(hr);
		t.setMin(min);
		t.setSec(sec);
		return *this;
	}
};

#endif