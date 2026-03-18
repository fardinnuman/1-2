// O(n^2)

#include <iostream>

using namespace std;

int main()
{
    int n = 5;
    int arr[n] = {3, 4, 2, 1, 5};

    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int previous = i - 1;

        while (previous >= 0 && arr[previous] > current)
        {
            arr[previous + 1] = arr[previous];
            previous--;
        }
        arr[previous + 1] = current;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

