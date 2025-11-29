/*
Write an Account class with 2 data members and methods. The structure
of the Account class is:

class Account {
    int number;
    int amount;
    //Write methods
};

Now do the following:
i) Initialize 5 accounts
ii) Deposit money to an account
iii) Withdrawal money from an account
iv) Transfer money from one account to another
*/

#include <iostream>
using namespace std;

class Account
{
private:
    int number;
    int amount;

public:
    Account(int num, int amt)
    {
        number = num;
        amount = amt;
    }

    void deposit(int x)
    {
        amount += x;
        cout << "Deposited " << x << " to Account " << number << endl;
    }

    void withdraw(int x)
    {
        if (x <= amount)
        {
            amount -= x;
            cout << "Withdrew " << x << " from Account " << number << endl;
        }
    }

    void transfer(Account &to, int x)
    {
        if (x <= amount)
        {
            amount -= x;
            to.amount += x;
            cout << "Transferred " << x << " from Account " << number << " to Account " << to.number << endl;
        }
    }

    void show()
    {
        cout << "Account No: " << number << " | Balance: " << amount << endl;
    }
};

int main()
{
    Account a1(2403176, 20);
    Account a2(2403177, 3000);
    Account a3(2403178, 7000);
    Account a4(2403179, 2000);
    Account a5(2403180, 10000);

    cout << "-----------------------------------\n";
    cout << "Initial Account Balances:\n";
    cout << "-----------------------------------\n";
    a1.show();
    a2.show();
    a3.show();
    a4.show();
    a5.show();
    cout << "-----------------------------------\n";

    a1.deposit(1000);
    a2.withdraw(200);
    a3.transfer(a4, 500);

    cout << "-----------------------------------\n";
    cout << "Final Account Balances:\n";
    cout << "-----------------------------------\n";
    a1.show();
    a2.show();
    a3.show();
    a4.show();
    a5.show();

    return 0;
}
