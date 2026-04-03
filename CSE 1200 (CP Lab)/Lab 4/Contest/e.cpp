#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, count = 0;
    cin >> n >> m;

    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int x = a[n - 1]; x <= b[0]; x++)
    {
        int ok = 1;

        for (int i = 0; i < n; i++)
            if (x % a[i])
                ok = 0;

        for (int i = 0; i < m; i++)
            if (b[i] % x)
                ok = 0;

        if (ok)
            count++;
    }

    cout << count;

    return 0;
}
