#include <iostream>
using namespace std;

class A {
public:
    void Print() {  // Remove 'virtual' for first run
        cout << "Inside Print() of class A" << endl;
    }
};

class B : public A {
public:
    void Print() {  // Overridden in derived class
        cout << "Inside Print() of class B" << endl;
    }
};

int main() {
    // Part i
    A a;
    a.Print();

    // Part ii
    B b;
    b.Print();

    // Part iii
    A* p1;
    p1 = &a;
    p1->Print();

    // Part iv
    A* p2;
    p2 = &b;
    p2->Print();

    return 0;
}
