// Compile Time Polymorphism (Early/Static Binding)
// Function Overloading (Using Class) → Function names same, parameters different, return type doesn't matter
// Using Class

#include <bits/stdc++.h>

using namespace std;

class Print
{
public:
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
};

int main()
{
    Print p1;
    p1.Show();
    p1.Show(5);
    p1.Show(5, 7);
    p1.Show('N');
    p1.Show("Numan");

    return 0;
}