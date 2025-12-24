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
    B(int a,int b) : A(a){
        bx=b; cout<<"B Constructor\n";
    }
    ~B(){ cout<<"B Destructor\n"; }
    int getB(){ return bx; }
};

class C : public B {
private: int cx;
public:
    C(int a,int b,int c) : B(a,b){
        cx=c; cout<<"C Constructor\n";
    }
    int sum(){ return getA() + getB() + cx; }
    ~C(){ cout<<"C Destructor\n"; }
};

int main(){
    C c(10,20,30);
    cout<<"Sum = "<<c.sum()<<endl;
    return 0;
}
