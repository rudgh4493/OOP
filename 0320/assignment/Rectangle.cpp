#include <iostream>
using namespace std;

#include "Rectangle.h"

Rectangle::Rectangle() {
}

Rectangle::Rectangle(int w, int h) {
	width = w;
	height = h;
}
Rectangle::Rectangle(int e) {
	edge = e;
}

Rectangle::~Rectangle() {
}

double Rectangle::getArea() {
	return width * height;
}

void Rectangle::setedge(int w, int h)
{
	width = w;
	height = h;
}

double Rectangle::getwidth()
{
	return width;
}

double Rectangle::getheight()
{
	return height;
}


int Rectangle::isSquare() {
	if (width == height) {
		return 1;
	}
	else {
		return 0;
	}
}