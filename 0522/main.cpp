
#include <iostream>
using namespace std;
#include "Circle.h"

class Base {
public:
    virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived :public Base {
public:
    virtual void f() {
        cout << "Derived::f() called" << endl;
    }
};

class Base {
public:
    virtual ~Base() {
        cout << "Derived()" << endl;
    }
};

class Derived :public Base {
public:
    virtual ~Derived() {
        cout << "Derived()" << endl;
    }
};


void main() {

    Shape* pStart = NULL;
    Shape* pLast;
    

    pStart = new Circle();
    pLast = pStart;

    pLast = pLast->add(new Rect());
    pLast = pLast->add(new Line());
    pLast = pLast->add(new Circle());
    pLast = pLast->add(new Rect());

    Shape* p = pStart;
    while (p != NULL) {
        p->paint();
        p = p->getNext();
    }
    p = pStart;
    while (p != NULL) {
        Shape* q = p->getNext();
        delete p;
        p = q;
    }
    /*
    Derived* dp = new Derived();
    Base* bp = new Derived();

    delete dp;
    */
    /*
    Derived d, * pDer;
    pDer = &d;
    pDer->f();

    Base* pBase;
    pBase = pDer;
    pBase->f();
    */

    /*
    Circle circle;
    Shape* pShape = &circle;

    pShape->draw();
    */

}
