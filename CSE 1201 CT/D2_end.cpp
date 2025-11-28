// Deletion at the end

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
    n--;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}