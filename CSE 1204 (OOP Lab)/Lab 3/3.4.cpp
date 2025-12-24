#include <iostream>
using namespace std;

class A {
private:int ax;
public:
    A(int a){ ax=a; cout<<"A Constructor\n"; }
    ~A(){ cout<<"A Destructor\n"; }
    int getA(){ return ax; }
};

class B : public A {
private:int bx;
public:
    B(int a,int b):A(a){
        bx=b; cout<<"B Constructor\n";
    }
    ~B(){ cout<<"B Destructor\n"; }
};

class C : public A {
private:int cx;
public:
    C(int a,int c):A(a){
        cx=c; cout<<"C Constructor\n";
    }
    int sum(){ return getA() + cx; }
    ~C(){ cout<<"C Destructor\n"; }
};

int main() {
    B b(10,20);
    C c(5,30);
    cout<<"Sum in C = "<<c.sum()<<endl;
    return 0;
}
