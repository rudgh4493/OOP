#include <iostream>
using namespace std;

#include "Circle.h"

Circle::Circle() :radius(1) { //Circle(1) �߰� radius(1) �߰�
	//radius = 1;
	//cout << "�������� " << radius << "�� �� ����" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "�������� " << radius << "�� �� ����" << endl;
}

Circle::~Circle() {
	cout << "�������� " << radius << "�� �� �Ҹ�" << endl;
}



double Circle::getArea() {
	return 3.14 * radius * radius;
}
