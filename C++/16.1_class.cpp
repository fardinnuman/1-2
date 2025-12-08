#include <iostream>

using namespace std;

class employee
{
public:
    string name;
    int salary;
};

int main()
{

    employee har;
    har.name = "harry";
    har.salary = 100;

    cout << "The name of our first employee is " << har.name << " and his salary is " << har.salary << " taka" << endl;

    return 0;
}