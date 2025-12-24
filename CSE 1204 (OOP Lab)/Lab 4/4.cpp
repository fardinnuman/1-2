#include <iostream>
using namespace std;

class Bank2;

class Bank1 {
private:
    float money1;
public:
    Bank1(float m){
        money1 = m;
    }
    friend void Sum(Bank1, Bank2);
};
class Bank2 {
private:
    float money2;

public:
    Bank2(float m){
        money2 = m;
    }

    friend void Sum(Bank1, Bank2);
};

void Sum(Bank1 b1, Bank2 b2){
    float total = b1.money1 + b2.money2;
    cout << "Total Money = " << total << endl;
}

int main() {
    Bank1 b1(2000);
    Bank2 b2(4000);
    Sum(b1, b2);
}
