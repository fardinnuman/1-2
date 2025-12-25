#include <iostream>
using namespace std;

class Bank2;

class Bank1 {
private:
    float money1;

public:
    // Constructor to initialize money1
    Bank1(float m) {
        money1 = m;
    }

    // Friend function declaration
    friend void Sum(Bank1, Bank2);
};

class Bank2 {
private:
    float money2;

public:
    // Constructor to initialize money2
    Bank2(float m) {
        money2 = m;
    }

    // Friend function declaration
    friend void Sum(Bank1, Bank2);
};

// Friend function to calculate total money
void Sum(Bank1 b1, Bank2 b2) {
    cout << b1.money1 + b2.money2 << endl;
}

int main() {
    Bank1 b1(2000);
    Bank2 b2(4000);

    Sum(b1, b2);
    return 0;
}
