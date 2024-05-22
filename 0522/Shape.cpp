#include "Shape.h"

void Shape::draw()
{
	cout << "----Shape----" << endl;
}
void Shape::paint() {
	draw();
}
Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}