// Insertion at specific position

#include <iostream>
using namespace std;

int main()
{
    int arr[10], n, pos, x;
    cout << "Enter size of an array: ";
    cin >> n;
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    /////
    cout << "Enter insertion location (index): ";
    cin >> pos;
    cout << "Enter the value to insert: ";
    cin >> x;
    for (int i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = x;
    n++;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}