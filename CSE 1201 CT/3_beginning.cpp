// Insertion at the beginning

#include <iostream>
using namespace std;

int main()
{

    int arr[10], n, i, x;
    cout << "Enter size of an array: ";
    cin >> n;
    cout << "Enter elements of the array: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ////////
    cout << "Enter the value to insert at the beginning: ";
    cin >> x;
    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = x;
    n++;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}