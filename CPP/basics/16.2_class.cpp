#include <iostream>

using namespace std;

class employee
{
public:
    string name;
    int salary;

    void print_details()
    {
        cout << "The name of our first employee is " << this->name << " and his salary is " << this->salary << " taka" << endl;
    }
};

int main()
{

    employee e1;
    e1.name = "Fardin Numan";
    e1.salary = 10000;
    e1.print_details();

    return 0;
}