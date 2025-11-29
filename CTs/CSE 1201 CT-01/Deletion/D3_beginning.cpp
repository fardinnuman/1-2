// Deletion at the beginning

#include <iostream>
using namespace std;

int main()
{
    int arr[10], n;
    cout << "Enter size of an array: ";
    cin >> n;
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    /////
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    n--;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}