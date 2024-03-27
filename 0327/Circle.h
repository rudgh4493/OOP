#pragma once
class Circle
{
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	Circle(const Circle& c);
	double getArea();
	int getRadius();
	void setRadius(int r);

};

