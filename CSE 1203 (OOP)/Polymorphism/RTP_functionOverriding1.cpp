// Run Time Polymorphism (Late/Dynamic Binding)
// Function Overriding → Function names same in Parent and Child Class, parameters same, implementation different
// Objects from the Child Class always tries to call the function from Child Class and Override the function from the Parent Class
// If the Child Class doesn't have the function then it will call the function from the Parent Class

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
    Child c1;
    c1.getInfo();
    // ↑ Will call the function from Parent Class

    return 0;
}