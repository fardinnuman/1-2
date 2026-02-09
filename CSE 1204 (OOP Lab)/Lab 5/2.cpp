#include <iostream>
using namespace std;

class A {
public:
    virtual void Print() = 0;  // Pure virtual function
};

class B : public A {
public:
    void Print() {  // Implementation of pure virtual function
        cout << "Inside Print() of class B" << endl;
    }
};

int main() {
    // Part iii (Invalid: cannot instantiate abstract class)
    // A a;  
    // a.Print();

    // Part iv
    B b;
    b.Print();

    // Part iii using pointer (Invalid: cannot instantiate abstract class)
    // A* p1;
    // A a_obj;
    // p1 = &a_obj;
    // p1->Print();

    // Part iv using pointer
    A* p2;
    p2 = &b;
    p2->Print();

    return 0;
}
