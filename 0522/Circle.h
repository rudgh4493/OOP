#pragma once
#include "Shape.h"
class Circle : public Shape
{
public: int x;
	  virtual void draw() {
		  Shape::draw();
		  cout << "Circle" << endl;
	  }
};

class Rect :public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};


class Line:public Shape {
	virtual void draw() {
		cout << "Line" << endl;
	}
};