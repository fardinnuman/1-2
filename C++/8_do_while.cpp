#include <iostream>

using namespace std;

int main()
{

    int index = 1;

    do
    {
        cout << "We are at index number: " << index << endl;
        index++;
    } while (index > 3453); // do while runs atleast once even if condition true or false then checks the condition and run depending on the condition

    return 0;
}