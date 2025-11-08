#include <iostream>

using namespace std;

class employee
{
public:
    string name;
    int salary;

    employee(string n, int s, int sp)
    {
        this->name = n;
        this->salary = s;
        this->secret_password = sp;
    }

    void print_details()
    {
        cout << "The name of our first employee is " << this->name << " and his salary is " << this->salary << " taka" << endl;
    }

    void get_secret_password()
    {
        cout << "The secret password of employee is " << this->secret_password << endl;
    }

private:
    int secret_password;
};

int main()
{

    employee e1("Fardin Numan", 10000, 123456);
    e1.print_details();
    e1.get_secret_password();
    // cout << e1.secret_password; ERROR because PRIVATE

    return 0;
}