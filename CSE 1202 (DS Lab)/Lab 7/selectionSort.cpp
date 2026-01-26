#include <iostream>

using namespace std;

int main()
{
    int n = 5;
    int arr[n] = {3, 4, 2, 1, 5};

    for (int i = 0; i < n - 1; i++)
    {
        int smallestIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIndex])
                smallestIndex = j;
        }
        swap(arr[i], arr[smallestIndex]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

