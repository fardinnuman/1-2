#include <iostream>

using namespace std;

int main()
{
    float a = 34.53;
    float *ptra;
    ptra = &a;

    cout << "The value of a is: " << a << endl;     // value
    cout << "The value of a is: " << *ptra << endl; // value

    cout << "The address of a is: " << &a << endl;   // address
    cout << "The address of a is: " << ptra << endl; // address

    return 0;
}