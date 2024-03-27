
#include <iostream>
#include "Circle.h"

using namespace std;


void swap(int  &a, int  &b) {
	int tmp;
	cout << "a: " << a << "\tb: " << b << endl;
	tmp = a;
	a = b;
	b = tmp;
	cout << "a: " << a << "\tb: " << b << endl;
}

void increase(Circle &c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}

Circle getCircle() {
	Circle tmp(30);
	return tmp;
}

bool average(int a[], int size, int &avg) {
	if (size <= 0) return false;
	int sum = 0;
	for (int i = 0; i < size; i++) sum += a[i];
	return sum / size;
	return true;
}

char& find(char s[], int index) {
	return s[index];
}

int main() {
	/*
	int x[] = { 1,2,3,4 };
	int avg;
	if (average(x, -4, avg))
		cout<< "avg: " << avg << endl;
	else
		cout << "매개변수오류" << endl;
	cout << "avg: " << avg << endl;
	*/
	/*
	Circle c;
	cout << c.getArea() << endl;

	c = getCircle();
	*/
/*
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
	*/
/*	int m = 2, n = 9;
	cout << "m: " << m << "\tn: " << n << endl;
	swap(m, n);
	cout << "m: " << m << "\tn: " << n << endl;
	*/
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S';
	cout << name << endl;

	char& ref = find(name, 2);
	ref = 't';
	cout << name << endl;


	return 0;


}