// Run Time Polymorphism (Late/Dynamic Binding)
// Function Overriding → Function names same in Parent and Child Class, parameters same, implementation different
// Using Pointers and Virtual Function

#include <bits/stdc++.h>

using namespace std;

class Parent
{
public:
    virtual void getInfo()
    {
        cout << "Parent Class" << endl;
    }
};

class Child : public Parent
{
public:
    void getInfo()
    {
        cout << "Child Class" << endl;
    }
};

int main()
{
    Parent *ptr;
    Child c1;
    ptr = &c1;

    ptr->getInfo();
    // ↑ Will call the function from Child Class 
    // Because We used the keyword Virtual before the function of the Parent Class

    return 0;
}