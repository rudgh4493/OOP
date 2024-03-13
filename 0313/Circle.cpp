#include <iostream>
using namespace std;

#include "Circle.h"

Circle::Circle() :radius(1) { //Circle(1) 추가 radius(1) 추가
	//radius = 1;
	//cout << "반지름이 " << radius << "인 원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "반지름이 " << radius << "인 원 생성" << endl;
}

Circle::~Circle() {
	cout << "반지름이 " << radius << "인 원 소멸" << endl;
}



double Circle::getArea() {
	return 3.14 * radius * radius;
}
