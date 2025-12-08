#include <iostream>
using namespace std;

int main()
{
    int arr[10], n, x, i;
    cout << "Enter the size of an array: ";
    cin >> n;
    cout << "Enter elements of the array: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter element to search: ";
    cin >> x;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << "Element found at index: " << i;
            break;
        }
    }
    if (i == n)
    {
        cout << "Element not found";
    }
    return 0;
}