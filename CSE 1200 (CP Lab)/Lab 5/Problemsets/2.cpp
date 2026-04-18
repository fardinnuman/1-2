#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;

    if (m % n != 0)
    {
        cout << -1;
        return 0;
    }

    long long x = m / n;
    int moves = 0;

    while (x % 2 == 0)
    {
        x /= 2;
        moves++;
    }

    while (x % 3 == 0)
    {
        x /= 3;
        moves++;
    }

    if (x != 1)
        cout << -1;
    else
        cout << moves;

    return 0;
}

