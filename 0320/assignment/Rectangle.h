#pragma once
#define RECTANGLE_H
class Rectangle {
public:
	int width;
	int height;
	int edge;
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(int e);

	int isSquare();
	double getArea();
	void setedge(int w, int h);
	double getwidth();
	double getheight();
	~Rectangle();
};