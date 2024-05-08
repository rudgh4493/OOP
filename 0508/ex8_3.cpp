#include <iostream>
#include "TV.h"
using namespace std;

int main()
{
	SmartTV htv("192.0.0.1", 32);
	cout << "size : " << htv.getSize() << endl;
	cout << "videoIn : " << htv.getVideoIn() << endl;
	cout << "IP : " << htv.getIpAddr() << endl;

}