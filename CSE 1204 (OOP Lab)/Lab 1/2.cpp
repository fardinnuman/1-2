#include <iostream>
using namespace std;

class Account
{
private:
    int number;
    int amount;

public:
    // Constructor to initializer list
    Account(int num, int amt) : number(num), amount(amt) {}

    // To deposit money
    void deposit(int x)
    {
        amount += x;
        cout << "Deposited " << x << " to Account " << number << endl;
    }

    // To withdraw money with balance check
    void withdraw(int x)
    {
        if (x <= amount)
        {
            amount -= x;
            cout << "Withdrew " << x << " from Account " << number << endl;
        }
        else
        {
            cout << "Insufficient balance in Account " << number << endl;
        }
    }

    // To transfer money to another account
    void transfer(Account &to, int x)
    {
        if (x <= amount)
        {
            amount -= x;
            to.amount += x;
            cout << "Transferred " << x << " from Account " << number
                 << " to Account " << to.number << endl;
        }
        else
        {
            cout << "Insufficient balance in Account " << number
                 << " for transfer" << endl;
        }
    }

    // To display account details
    void show() const
    {
        cout << "Account No: " << number << " | Balance: " << amount << endl;
    }
};

int main()
{
    // To initialize 5 accounts
    Account a1(2403176, 20);
    Account a2(2403177, 3000);
    Account a3(2403178, 7000);
    Account a4(2403179, 2000);
    Account a5(2403180, 10000);

    cout << "Initial Account Balances:\n";
    a1.show();
    a2.show();
    a3.show();
    a4.show();
    a5.show();

    // To perform some transactions
    a1.deposit(1000);
    a2.withdraw(200);
    a3.transfer(a4, 500);

    cout << "Final Account Balances:\n";
    a1.show();
    a2.show();
    a3.show();
    a4.show();
    a5.show();

    return 0;
}
