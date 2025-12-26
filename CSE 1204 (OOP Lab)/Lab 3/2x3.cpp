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

class B {
private:
    int p;
protected:
    int q;
public:
    int r;
public:
    B() { p=5; q=15; r=25; }
};

class C : public A, public B {
public:
    void show() {
        // cout << x; // Not accessible
        cout << "y: " << y << endl; // Accessible
        cout << "z: " << z << endl; // Accessible
        // cout << p; // Not accessible
        cout << "q: " << q << endl; // Accessible
        cout << "r: " << r << endl; // Accessible
    }
};

int main() {
    C c;
    c.show();
    return 0;
}
