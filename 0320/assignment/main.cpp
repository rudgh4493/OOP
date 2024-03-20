#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {
	int n;
	cout << "입력할 정수의 갯수는 : ";
	cin >> n;

	Rectangle* p = new Rectangle[n];

	if (!p)
		return 0;

	//너비 높이입력
	for (int i = 0; i < n; i++) {
		int w, h;
		cout << "너비와 높이를 정수로 입력하세요 : ";
		cin >> w>>h;
		p[i].setedge(w,h);
	}
	//출력
	int count = 0;
	for (int i = 0; i < n; i++) {
		double area = p[i].getArea();
		cout<< "너비가 " << p[i].getwidth() <<", 높이가 " <<p[i].getheight() << "인 사각형의 넓이 "<<area << endl;

		//정사각형 개수 구하기
		if (p[i].isSquare()) {
			count++;
		}
	}
	cout << "정사각형은 " << count << "개 입니다" << endl;



	delete [] p;
	return 0;
}
