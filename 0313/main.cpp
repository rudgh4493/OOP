#include <iostream>
using namespace std;

int main() {
	Circle donut;
	//donut.radius = 1;
	double area = donut.getArea();
	cout << "donut������ " << area << endl;
	
	//	Circle pizza;
	//pizza.radius = 20;
	Circle pizza(20);
	pizza.radius = 22;
	area = pizza.getArea();
	cout << "pizza������ " << area << endl;

	return 0;
}
