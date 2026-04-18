#include <bits/stdc++.h>
using namespace std;

int sumDigits(long long x)
{
    int s = 0;
    while (x)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main()
{
    long long n;
    cin >> n;

    int ans = sumDigits(n);

    long long t = 0;
    long long p = 1;

    while (p <= n)
    {
        t = t + 9 * p;
        if (t <= n)
        {
            long long a = t;
            long long b = n - a;
            ans = max(ans, sumDigits(a) + sumDigits(b));
        }
        p *= 10;
    }

    cout << ans;

    return 0;
}

