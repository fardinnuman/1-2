#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a = 1;
        for (long long i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                long long d1 = i, d2 = n / i;
                if (d1 <= n / 2)
                    a = max(a, d1);
                if (d2 <= n / 2)
                    a = max(a, d2);
            }
        }
        cout << a << " " << n - a << "\n";
    }
}
