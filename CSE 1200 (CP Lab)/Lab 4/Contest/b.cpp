#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (k >= arr[i])
        {
            k -= arr[i];
            count++;
        }
        else
        {
            break;
        }
    }

    cout << count << endl;
    return 0;
}

