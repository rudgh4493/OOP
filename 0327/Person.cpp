#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Person.h"
using namespace std;


Person::Person(int id, const char* name)
{
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this-> name, name);
}

Person::Person(const Person& person)
{
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "���� ������ ����, ���� ��ü�� �̸�:" << this->name << endl;
}

Person::~Person()
{
	if (name)
		delete[] name;
}

void Person::changeName(const char* name)
{
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

void Person::show()
{
	cout << id << ',' << name << endl;
}
