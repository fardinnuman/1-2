#include <iostream>
using namespace std;

class A {
private:int ax;
public:
    A(int a){ ax=a; cout<<"A Constructor\n"; }
    ~A(){ cout<<"A Destructor\n"; }
    int getA(){ return ax; }
};

class B : virtual public A {
private:int bx;
public:
    B(int a,int b):A(a){
        bx=b; cout<<"B Constructor\n";
    }
    ~B(){ cout<<"B Destructor\n"; }
    int getB(){ return bx; }
};

class C : virtual public A {
private:int cx;
public:
    C(int a,int c):A(a){
        cx=c; cout<<"C Constructor\n";
    }
    ~C(){ cout<<"C Destructor\n"; }
    int getC(){ return cx; }
};

class D : public B, public C {
private:int dx;
public:
    D(int a,int b,int c,int d) : 
        A(a), B(a,b), C(a,c)
    {
        dx=d;
        cout<<"D Constructor\n";
    }

    int sum(){
        return getA() + getB() + getC() + dx;
    }

    ~D(){ cout<<"D Destructor\n"; }
};

int main(){
    D d(1,2,3,4);
    cout<<"Sum = "<<d.sum()<<endl;
    return 0;
}
