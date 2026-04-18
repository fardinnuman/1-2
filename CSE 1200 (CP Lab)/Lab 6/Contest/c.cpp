#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long calorie[100005];

    for (int i = 0; i < n; i++)
    {
        cin >> calorie[i];
    }

    sort(calorie, calorie + n, greater<long long>());

    long long miles = 0;
    long long power = 1;

    for (int i = 0; i < n; i++)
    {
        miles += calorie[i] * power;
        power = power * 2;
    }

    cout << miles << endl;

    return 0;
}
