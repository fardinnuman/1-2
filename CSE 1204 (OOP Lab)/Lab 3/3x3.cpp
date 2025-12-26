#include <iostream>
using namespace std;

class A {
private:
    int ax;
public:
    A() { ax = 10; } // Constructor
    ~A() { }         // Destructor
    int getAx() { return ax; }
};

class B {
private:
    int bx;
public:
    B() { bx = 20; } // Constructor
    ~B() { }         // Destructor
    int getBx() { return bx; }
};

class C : public A, public B {
private:
    int cx;
public:
    C() { cx = 30; } // Constructor
    ~C() { }         // Destructor
    void sum() { cout << getAx() + getBx() + cx << endl; } // Sum method
};

int main() {
    C c;
    c.sum();
    return 0;
}
