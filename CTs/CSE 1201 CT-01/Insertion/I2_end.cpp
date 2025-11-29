// Insertion at the end

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
    /////
    cout << "Enter the value to insert at the end: ";
    cin >> x;
    arr[i] = x;
    n++;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}