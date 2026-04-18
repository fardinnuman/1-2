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

    int day, month;
    cin >> day >> month;

    int count = 0, sum = 0;

    for (int i = 0; i < month && i < n; i++)
    {
        sum = sum + arr[i];
    }

    if (sum == day)
        count++;

    for (int i = month; i < n; i++)
    {
        sum += arr[i] - arr[i - month];
        if (sum == day)
            count++;
    }

    cout << count << endl;

    return 0;
}

