#include <iostream>

using namespace std;

int main()
{
    int arr[3] = {1, 2, 3};

    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;

    int marks[6];

    for (int i = 0; i < 6; i++)
    {
        cout << "Enter the marks of " << i + 1 << "th student: ";
        cin >> marks[i];
    }

    for (int i = 0; i < 6; i++)
    {
        cout << "Marks of " << i + 1 << "th student is: " << marks[i] << endl;
    }

    return 0;
}