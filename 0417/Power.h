#pragma once
class Power {

	int kick, punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
//	Power operator+(Power op2);
//	bool operator==(Power op2);
//	Power& operator+=(Power op2);
//	Power& operator++();
//	Power& operator++(int a);

	friend Power& operator++(Power& op);
	friend Power operator++(Power& op, int x);
	friend Power operator+(int op1, Power op2);
	friend Power operator+(Power op1, Power op2);
	Power& operator << (int n);
};