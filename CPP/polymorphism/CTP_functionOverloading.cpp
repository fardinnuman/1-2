// Compile Time Polymorphism (Early/Static Binding)
// Function Overloading → Function names same, parameters different, return type doesn't matter

#include <bits/stdc++.h>

using namespace std;

// Difference in parameter TYPE ↓
void Show()
{
    cout << "No Parameter" << endl;
}

void Show(int n)
{
    cout << "Integer: " << n << endl;
}

void Show(char c)
{
    cout << "Character: " << c << endl;
}

void Show(string name)
{
    cout << "Name: " << name << endl;
}

// Difference in parameter NUMBER ↓
void Show(int n, int m)
{
    cout << "Integers: " << n << ", " << m << endl;
}

int main()
{
    Show();
    Show(5);
    Show(5, 7);
    Show('N');
    Show("Numan");

    return 0;
}
