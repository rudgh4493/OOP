#pragma once
#define CIRCLE_H
class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	double getArea();
	void setRadius(int r);
	double getRadius();
	~Circle();
};