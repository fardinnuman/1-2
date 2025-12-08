#include <iostream>
using namespace std;

class Test{
public:
    int Sum(int a){
        cout<<a<<endl;
        return a;
    }
    int Sum(int a, int b){
        cout<<a + b<<endl;
        return a + b;
    }
    double Sum(double a, int b){
        cout<<a + b<<endl;
        return a + b;
    }
    double Sum(int a, double b){
        cout<<a + b<<endl;
        return a + b;
    }
    double Sum(double a, double b){
        cout<<a + b<<endl;
        return a + b;
    }
};
int main(){
    Test t1;
    t1.Sum(10);       
    t1.Sum(10,20);      
    t1.Sum(5.7,20);
    t1.Sum(10,2.6);
    t1.Sum(10.5,20.5);
}
