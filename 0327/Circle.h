#pragma once
class Circle
{
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
	int getRadius();
	void setRadius(int r);
};

