#include <iostream>
//#include <cstring>
#include <string>
using namespace std;

double area(int r);

int main() {
	cout << "�ּҸ� �Է��ϼ��� : ";

	//char address[100];
	//cin >> address;
	string address;
	//cin.getline(address, 100, '\n');
	getline(cin, address);
	cout << "�ּ� : " << address << endl;
	return 0;
}

double area(int r) {
	return 3.14 * r * r;
}

