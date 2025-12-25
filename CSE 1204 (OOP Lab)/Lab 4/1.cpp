#include <iostream>
using namespace std;

class Test {
public:
    int Sum(int a) { 
        return a; // One integer
    }
    int Sum(int a, int b) {
        return a + b; // Two integers
    }
    double Sum(double a, int b) {
        return a + b; // Double and integer
    }
    double Sum(int a, double b) {
        return a + b; // Integer and double
    }
    int Sum(double a, double b) {
        return a + b; // Two double
    }
};

int main() {
    Test t;
    // Calls to overloaded Sum() methods
    cout << t.Sum(10) << endl;
    cout << t.Sum(10,20) << endl;
    cout << t.Sum(5.7,20) << endl;
    cout << t.Sum(10,2.6) << endl;
    cout << t.Sum(10.5,20.5) << endl;

    return 0;
}
