#include <iostream>
using namespace std;

class A
{
protected:
    int y;

public:
    int z;
    A()
    {
        y = 1;
        z = 2;
    }
};

class B : virtual public A
{
};
class C : virtual public A
{
};

class D : public B, public C
{
public:
    void access()
    {
        cout << "Hybrid (Diamond) Inheritance\n";
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
};

int main()
{
    D d;
    d.access();
    return 0;
}
