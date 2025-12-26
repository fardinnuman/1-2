#include <iostream>
using namespace std;

class A {
private:
    int x;
protected:
    int y;
public:
    int z;
public:
    A() { x=10; y=20; z=30; }
};

class B : public A {
public:
    void show() {
        // cout << x; // Not accessible
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
};

class C : public A {
public:
    void show() {
        // cout << x; // Not accessible
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
};

int main() {
    B b;
    C c;
    b.show();
    c.show();
    return 0;
}
