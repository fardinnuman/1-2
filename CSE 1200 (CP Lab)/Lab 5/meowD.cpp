#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }

        long long a[100005];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        int minTeam = n;
        int i = 0;

        while (i < n)
        {
            int j = i;

            // build consecutive chain
            while (j + 1 < n && a[j + 1] == a[j] + 1)
            {
                j++;
            }

            int size = j - i + 1;
            minTeam = min(minTeam, size);

            i = j + 1;
        }

        cout << minTeam << endl;
    }

    return 0;
}