// Run Time Polymorphism (Late/Dynamic Binding)
// Function Overriding → Function names same in Parent and Child Class, parameters same, implementation different
// Objects from the Child Class always tries to call the function from Child Class and Override the function from the Parent Class

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
public:
    void getInfo()
    {
        cout << "Child Class" << endl;
    }
};

int main()
{
    Child c1;
    c1.getInfo(); 
    // ↑ Will NOT call the function from Parent Class
    // Will Override the Parent Class, and call the function from Child Class

    // So how do we call the function from Parent Class?
    // Using Scope Resolution :: Operator
    Child c2;
    c2.Parent::getInfo();
    // ↑ Will call the function from Parent Class

    return 0;
}