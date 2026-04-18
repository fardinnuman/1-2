#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int f[55];
    for (int i = 0; i < m; i++)
    {
        cin >> f[i];
    }

    sort(f, f + m);

    int min_diff = INT_MAX;

    for (int i = 0; i <= m - n; i++)
    {
        int diff = f[i + n - 1] - f[i];
        if (diff < min_diff)
        {
            min_diff = diff;
        }
    }

    cout << min_diff << endl;

    return 0;
}

