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


int Rectangle::isSquare() {
	if (width == height) {
		return 1;
	}
	else {
		return 0;
	}
}