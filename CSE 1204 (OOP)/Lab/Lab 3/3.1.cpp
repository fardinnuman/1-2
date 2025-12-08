#include <iostream>
using namespace std;

class A {
private: int ax;
public:
    A(int a){ ax=a; cout<<"A Constructor\n"; }
    ~A(){ cout<<"A Destructor\n"; }
    int getA(){ return ax; }
};

class B : public A {
private: int bx;
public:
    B(int a,int b) : A(a) {
        bx = b; 
        cout<<"B Constructor\n";
    }
    int sum() { return getA() + bx; }
    ~B(){ cout<<"B Destructor\n"; }
};

int main(){
    B b(10,20);
    cout<<"Sum = "<<b.sum()<<endl;
    return 0;
}
