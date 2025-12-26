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
class C : public A {};

class D : public B, public C {
public:
    void show() {
        // cout << x; // Not accessible
        cout << "B::y: " << B::y << endl;
        cout << "B::z: " << B::z << endl;
        cout << "C::y: " << C::y << endl;
        cout << "C::z: " << C::z << endl;
    }
};

int main() {
    D d;
    d.show();
    return 0;
}
