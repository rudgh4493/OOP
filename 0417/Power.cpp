
#include <iostream>
#include "Power.h"
using namespace std;
void Power::show()
{
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}
/*
Power Power::operator+(Power op2) {
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

bool Power::operator==(Power op2)
{
	if ((kick == op2.kick) && (punch == op2.punch))
		return true;
	else
		return false;
}

Power& Power::operator+=(Power op2)
{
	kick += op2.kick;
	punch+= op2.punch;
	return *this;

}

Power& Power::operator++()
{
	kick++;
	punch++;
	return *this;
}

Power& Power::operator++(int a)
{
	Power tmp = *this;
	kick++;
	punch++;
	return tmp;
}
*/
Power& operator++(Power& op)
{
	op.kick++;
	op.punch++;
	return op;
}

Power operator++(Power& op, int x)
{
	Power tmp = op;
	op.kick++;
	op.punch;
	return tmp;
}

Power operator+(int op1, Power op2)
{
	Power tmp;
	tmp.kick = op2.kick + op1;
	tmp.punch = op2.punch + op1;
	return tmp;
}

Power operator+(Power op1, Power op2)
{
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.kick;
	return tmp;
}
Power& Power::operator <<(int n) {
	kick += n;
	punch += n;
	return *this; // 이 객체의 참조 리턴
}