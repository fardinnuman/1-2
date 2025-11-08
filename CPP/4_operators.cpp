#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Enter first number: " << endl;
    cin >> a;
    cout << "Enter second number: " << endl;
    cin >> b;

    cout << "The sum is: " << a + b << endl;
    cout << "The diff is: " << a - b << endl;
    cout << "The product is: " << a * b << endl;
    cout << "The div is: " << a / b << endl;
    cout << "The div is: " << (float)a / b << endl; // TYPECASTING
    cout << "The remainder is: " << a % b << endl;

    return 0;
}