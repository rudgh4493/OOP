#include <iostream>
#include <string>
#include "Person.h"
#include "Rect.h"
using namespace std;

void star(int a = 5);
void msg(int id, string text = "");
float square(float a) {
	return a * a;
}
double square(double a) {
	return a * a;
}
int add(int a, int b) {
	return a + b;
}
int add(int a, int &b) {
	b = b + a;
	return b;
}
void star(int a){
	for (int i = 0;i < a;i++) {
		cout << "*";
	}
	cout << endl;
}
void msg(int id, string text){
	cout << id << ' ' << text << endl;
}
void msg(int id) {
	cout << id << endl;
}

class Math {
public:
	static int abs(int a) {
		return a > 0 ? a : -a;
	}
	static int max(int a, int b) {
		return (a > b) ? a : b;
	}
	static int min(int a, int b) {
		return (a > b) ? b : a;
	}
};


int main() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b))
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;
	/*
	cout <<Math::abs(-5) << endl;
	cout << Math::max(10, 5) << endl;
	cout << Math::min(10, 5) << endl;
	*/
	/*
	Person han;
	han.money = 100;
	han.sharedMoney = 200;
	cout << han.money << " " << han.sharedMoney << endl;

	Person lee;
	lee.money = 150;
	lee.addMoney(200);
	Person::addShared(200);
//	lee.addShared(200);
	cout << lee.money << " "<<lee.sharedMoney << endl;
	*/
	/*
	msg(1);
	*/
	/*
	int s = 10, t = 20;
	cout << add(s, t);
	
	*/
	/*
	cout << square(3.0) << endl;
	cout << square(3) << endl;
	*/
	/*
	for (int i = 0;i < 10;i++) star();
	msg(5);
	msg(10, "hello");
	*/
	}
