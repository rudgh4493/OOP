#include <iostream>
#include <string>
using namespace std;

class Point {
protected:
	int x, y;
public:
	void set(int x, int y){
		this->x = x; this->y = y; 
	}
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}

};
class ColorPoint : public Point {
		string color;// 점의 색
public:
	void setColor(string color) {
		this->color = color; 
	}
	void showColorPoint();
	bool equals(ColorPoint p);
};
void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint(); // Point의 showPoint() 호출
}
bool ColorPoint::equals(ColorPoint p) {
	if (x == p.x && y == p.y && color == p.color) {

	}
}

int main() {
	Point p; 
	ColorPoint cp;
	cp.set(3, 4);
	cp.showPoint();

	cp.setColor("Red");
	cp.showColorPoint();
}
