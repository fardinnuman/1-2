#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    while (q)
    {
        int x;
        cin >> x;

        int *it = lower_bound(arr, arr + n, x);
        int idx = it - arr + 1;

        if (it != arr + n && *it == x)
        {
            cout << "Yes " << idx << endl;
        }

        else
        {
            cout << "No " << idx << endl;
        }
        q--;
    }

    return 0;
}