#include <iostream>
//#include <cstring>
#include <string>
using namespace std;

double area(int r);

int main() {
	cout << "林家甫 涝仿窍技夸 : ";

	//char address[100];
	//cin >> address;
	string address;
	//cin.getline(address, 100, '\n');
	getline(cin, address);
	cout << "林家 : " << address << endl;
	return 0;
}

double area(int r) {
	return 3.14 * r * r;
}

