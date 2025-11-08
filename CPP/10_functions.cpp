#include <iostream>

using namespace std;

// f(x) = x^2 + 2
int add(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

int main()
{
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    cout << "The sum is: " << add(a, b);

    return 0;
}