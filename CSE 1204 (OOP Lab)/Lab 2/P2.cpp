#include <iostream>
using namespace std;

class A {
private:
    int a, b;

public:
    void setData(int x, int y) {
        a = x;
        b = y;
    }

    // Copy constructor
    A(const A &obj) {
        a = obj.a;
        b = obj.b;
    }

    A() {}

    void show() const {
        cout << "a = " << a << ", b = " << b << endl;
    }
};

int main() {
    A obj1;
    obj1.setData(10, 20);

    A obj2(obj1);   // Copy constructor call

    obj1.show();
    obj2.show();

    return 0;
}
