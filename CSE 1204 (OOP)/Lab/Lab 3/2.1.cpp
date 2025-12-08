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
        x = 10;
        y = 20;
        z = 30;
    }
};

class B : public A
{
public:
    void access()
    {
        cout << "Single Inheritance (A → B)\n";
        cout << "x: Not Accessible\n";
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
};

int main()
{
    B b;
    b.access();
    return 0;
}
