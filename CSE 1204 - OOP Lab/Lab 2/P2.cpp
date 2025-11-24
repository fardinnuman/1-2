#include <iostream>
using namespace std;

class A {
    private:
    int a, b;
    
    public:
    void SetData(int x, int y) {
        a = x;
        b = y;
    }    
    
    A(const A &obj) {
        a = obj.a;
        b = obj.b;
    }
    
    A() {
        a = 0;
        b = 0;
    }

    void show() {
        cout << "a = " << a << ", b = " << b << endl;
    }
};

int main() {
    A obj1;
    obj1.SetData(10, 20);

    A obj2(obj1);

    cout << "Object 1: ";
    obj1.show();

    cout << "Object 2: ";
    obj2.show();

    return 0;
}