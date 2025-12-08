#include <iostream>
using namespace std;

class Student
{

private:
    int roll;

public:
    void setRoll(int r)
    {
        roll = r;
    }

    int getRoll()
    {
        return roll;
    }
};

int main()
{
    Student s1;

    s1.setRoll(2403179);

    cout << s1.getRoll();
}