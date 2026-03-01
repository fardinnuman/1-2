// Compile Time Polymorphism (Early/Static Binding)
// Constructor Overloading → Constructor names same, parameters different, return type doesn't matter
// Using Class

#include <bits/stdc++.h>

using namespace std;

class Print
{
public:
    // Difference in parameter TYPE ↓
    Print()
    {
        cout << "No Parameter" << endl;
    }

    Print(int n)
    {
        cout << "Integer: " << n << endl;
    }

    Print(char c)
    {
        cout << "Character: " << c << endl;
    }

    Print(string name)
    {
        cout << "Name: " << name << endl;
    }

    // Difference in parameter NUMBER ↓
    Print(int n, int m)
    {
        cout << "Integers: " << n << ", " << m << endl;
    }
};

int main()
{
    Print p1;            

    Print p2(5);         
    Print p3('A');       
    Print p4("Numan");   
    Print p5(10, 20);

    return 0;
}