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
        x = 1;
        y = 2;
        z = 3;
    }
};

class B : public A
{
};

class C : public B
{
public:
    void access()
    {
        cout << "Multilevel Inheritance (A → B → C)\n";
        cout << "x: Not Accessible\n";
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
};

int main()
{
    C c;
    c.access();
    return 0;
}
