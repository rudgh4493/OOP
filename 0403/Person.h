#pragma once
class Person {
public:
	int money;	//개인 소유의 돈
	void addMoney(int money);

	static int sharedMoney;	//공금
	static void addShared(int n);
};