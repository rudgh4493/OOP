
#include "Circle.h"
#include "iostream"
using namespace std;



Circle::Circle()
{
	radius = 1;
	cout << "积己磊 角青, radius: " << radius << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "积己磊 角青, radius: " << radius << endl;
}
Circle::~Circle()
{
	cout << "家戈磊 角青, radius: " << radius << endl;
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