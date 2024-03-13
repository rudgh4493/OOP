#include <iostream>
using namespace std;

int main() {
	Circle donut;
	//donut.radius = 1;
	double area = donut.getArea();
	cout << "donut면적은 " << area << endl;
	
	//	Circle pizza;
	//pizza.radius = 20;
	Circle pizza(20);
	pizza.radius = 22;
	area = pizza.getArea();
	cout << "pizza면적은 " << area << endl;

	return 0;
}
