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

class B : public A {};

class C : public B {
public:
    void show() {
        // cout << x; // Not accessible
        cout << "y: " << y << endl; // Accessible
        cout << "z: " << z << endl; // Accessible
    }
};

int main() {
    C c;
    c.show();
    return 0;
}
