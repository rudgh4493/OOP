#include <iostream>
using namespace std;

#include "Rectangle.h"
int main() {

	Rectangle rect;

	rect.width = 3;
	rect.height = 5;

	cout << "�簢���� ������ " << rect.getArea() << endl;


	Rectangle rect1;

	Rectangle rect2(3, 5);

	Rectangle rect3(3);

	if (rect1.isSquare()) cout << "rect1�� ���簢���̴�." << endl;

	if (rect2.isSquare()) cout << "rect2�� ���簢���̴�." << endl;

	if (rect3.isSquare()) cout << "rect3�� ���簢���̴�." << endl;
}