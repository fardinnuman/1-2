#include <iostream>
using namespace std;

int arr[10], n, x, i;
int binarySearch(int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    cout << "Enter the size of an array: ";
    cin >> n;
    cout << "Enter elements of the array in ascending order: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter element to search: ";
    cin >> x;
    int result = binarySearch(0, n - 1);

    if (result == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found at index: " << result;
    }

    return 0;
}
