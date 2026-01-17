// Run Time Polymorphism (Late/Dynamic Binding)
// Function Overriding → Function names same in Parent and Child Class, parameters same, implementation different
// Using Pointers

#include <bits/stdc++.h>

using namespace std;

class Parent
{
public:
    void getInfo()
    {
        cout << "Parent Class" << endl;
    }
};

class Child : public Parent
{
};

int main()
{

    Parent *ptr;
    Child c1;
    ptr = &c1;

    ptr->getInfo();
    // ↑ Will call the function from Parent Class

    return 0;
}