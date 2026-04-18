#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
bool prime[N + 1];

void sieve()
{
    fill(prime, prime + N + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
                prime[j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n;
    cin >> n;

    while (n--)
    {
        long long x;
        cin >> x;

        long long r = sqrt(x);

        if (r * r == x && prime[r])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

