#include <iostream>
#include "Circle.h"
using namespace std;
void lastweek();

int main() {
	int n;
	cout << "입력할 정수의 갯수는 : ";
	cin >> n;

	Circle* p = new Circle[n];
	//int* p= new int[n];

	if (!p)
		return 0;
	//반지름 입력받기
	for (int i = 0; i < n; i++) {
		int r;
		cout << "반지름을 정수로 입력하세요 : ";
		cin >> r;
		p[i].setRadius(r);
	}
	//출력
	int count = 0;
	for (int i = 0; i < n; i++) {
		double area = p[i].getArea();
		cout<< "반지름이 " <<p[i].getRadius() << "인 원의 넓이 "<<area << endl;
		
		if (area >= 100 && area <= 200) {
			count++;
		}
	}
	//원의 면적이 100~200사이인 원의 갯수 출력
	cout << "면적이 100에서 200 사이인 원의 갯수 : " << count << endl;
	/**p = 55;
	int n = *p;
	cout << "*p : " << *p << endl;
	cout << "n : " << n << endl;*/


	delete [] p;
//	circle circlearray[2][3] =
//	{ {circle(100),circle(200),circle(300)}, {circle(11),circle(21),circle(31)} };
//	/*
//	circlearray[0][0].setradius(10);
//	circlearray[0][1].setradius(20);
//	circlearray[0][2].setradius(30);
//	circlearray[0][0].setradius(1);
//	circlearray[0][1].setradius(2);
//	circlearray[0][2].setradius(3);
//	*/
//
//	배열의 각 원소 객체의 멤버 접근
//		for (int j = 0; j < 2;j++)
//			for (int i = 0; i < 3; i++) {
//				cout << "circle (" << j << "," << i << ")의 면적은 " << circlearray[j][i].getarea() << endl;
//			}
//	/*
//	circle* p;
//	p = circlearray;
//
//	for (int i = 0; i < 3; i++) {
//		cout << "circle " << i << "의 면적은 " << p->getarea() << endl;
//		p++;	//배열의 다음 원소
//	}
//	*/
//	*/
	return 0;
}

void lastweek() {

	Circle donut;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza(20);
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;

	Circle* p;
	p = &donut;
	p->getArea();

	cout << "asdf" << p << endl;


}