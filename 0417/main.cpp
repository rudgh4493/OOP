#include <iostream>
#include "Power.h"
using namespace std;
int main()
{
	Power a(3, 5), b(4, 6), c;
	a.show();
	a << 3 << 5 << 6;
	a.show();
	/*
	c.show();
	c = 2+a;
	a.show();
	c.show();*/
	/*
	++a;
	a.show();
	*/
	/*
	b.show();
	if (a == b)
		cout << "같다" << endl;
	else
		cout << "다르다" << endl;
	*/
	/*
	c.show();
	c = a + b;
	cout << "연산 후" << endl;

	a.show();
	b.show();
	c.show();
	*/
	}
