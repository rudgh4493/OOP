#pragma once
class Person {
public:
	int money;	//���� ������ ��
	void addMoney(int money);

	static int sharedMoney;	//����
	static void addShared(int n);
};