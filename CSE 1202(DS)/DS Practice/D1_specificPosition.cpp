// Deletion at specific position

#include <iostream>
using namespace std;

int main()
{
    int arr[10], n, pos;
    cout << "Enter size of an array: ";
    cin >> n;
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    /////
    cout << "Enter position (index) to delete: ";
    cin >> pos;
    for (int i = pos + 1; i < n; i++)
    {
        arr[i-1] = arr[i];
    }
    n--;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}