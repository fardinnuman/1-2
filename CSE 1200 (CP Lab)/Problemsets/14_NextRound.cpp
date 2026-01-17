#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;

    int count = 0;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > arr[k-1])
        {
            count++;
        }
    }

    cout << count;

    return 0;
}