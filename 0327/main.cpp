
#include <iostream>
#include "Circle.h"
#include "Person.h"

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

Person f(Person person) {
	person.changeName("dummy");
	return person;
}

int main() {
	/*
	Circle src(30);
	Circle dest(src);

	cout << "원본의 면적: " << src.getArea() << endl;
	cout << "사본의 면적: " << dest.getArea() << endl;
	*/
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
	/*
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S';
	cout << name << endl;

	char& ref = find(name, 2);
	ref = 't';
	cout << name << endl;
	*/
	/*
	Person father(1, "Kitae");
	Person daughter(father);

	cout << "daughter객체 생성 직후" << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");
	cout << "daughter 이름을 Grace로 변경한 후" << endl;
	father.show();
	daughter.show();
	*/
	Person father(1, "Kitae");
	Person son = father;
	f(father);



	return 0;


}