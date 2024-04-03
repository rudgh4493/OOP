#include "Person.h"

void Person::addMoney(int money)
{
	this->money = money;

}

void Person::addShared(int n)
{
	sharedMoney += n;
}

int Person::sharedMoney = 10;
