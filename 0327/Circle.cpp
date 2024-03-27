
#include "Circle.h"
#include "iostream"
using namespace std;



Circle::Circle()
{
	radius = 1;
	cout << "������ ����, radius: " << radius << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "������ ����, radius: " << radius << endl;
}
Circle::Circle(const Circle& c)
{
	this->radius = c.radius;
	cout << "���� ������ ����, radius: " << radius << endl;
}
Circle::~Circle()
{
	cout << "�Ҹ��� ����, radius: " << radius << endl;
}

double Circle::getArea()
{
	return 3.14*radius*radius;
}

int Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(int r)
{
	radius = r;
}