#include <iostream>
using namespace std;

class A
{
private:
    int x;

protected:
    int y;

public:
    int z;
    A()
    {
        x = 5;
        y = 10;
        z = 15;
    }
};

class B : public A
{
public:
    void access()
    {
        cout << "Hierarchical Inheritance (A → B)\n";
        cout << "x: Not Accessible\n";
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
};

class C : public A
{
public:
    void access()
    {
        cout << "Hierarchical Inheritance (A → C)\n";
        cout << "x: Not Accessible\n";
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
};

int main()
{
    B b;
    C c;
    b.access();
    c.access();
    return 0;
}
