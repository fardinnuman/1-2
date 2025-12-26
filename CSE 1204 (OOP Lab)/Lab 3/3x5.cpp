#include <iostream>
using namespace std;

class A {
private:
    int ax;
public:
    A() { ax = 10; } // Constructor
    virtual ~A() { } // Destructor
    int getAx() { return ax; }
};

class B : virtual public A {
private:
    int bx;
public:
    B() { bx = 20; } // Constructor
    ~B() { }         // Destructor
    int getBx() { return bx; }
};

class C : virtual public A {
private:
    int cx;
public:
    C() { cx = 30; } // Constructor
    ~C() { }         // Destructor
    int getCx() { return cx; }
};

class D : public B, public C {
private:
    int dx;
public:
    D() { dx = 40; } // Constructor
    ~D() { }         // Destructor
    void sum() { cout << getAx() + getBx() + getCx() + dx << endl; } // Sum method
};

int main() {
    D d;
    d.sum();
    return 0;
}
