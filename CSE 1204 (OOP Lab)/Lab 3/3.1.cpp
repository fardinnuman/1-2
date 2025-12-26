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

class B : public A {
private:
    int bx;
public:
    B() { bx = 20; } // Constructor
    ~B() { }         // Destructor
    void sum() { cout << getAx() + bx << endl; } // Sum method
};

int main() {
    B b;
    b.sum();
    return 0;
}
