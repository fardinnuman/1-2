#include <bits/stdc++.h>
using namespace std;

struct Task
{
    int t, d;
};

bool cmp(Task a, Task b)
{
    return a.d < b.d;
}

int main()
{
    int n;
    cin >> n;

    Task a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].t >> a[i].d;

        sort(a, a + i + 1, cmp);

        int current_time = 0;
        int max_late = 0;

        for (int j = 0; j <= i; j++)
        {
            current_time += a[j].t;
            int late = current_time - a[j].d;
            if (late > max_late)
                max_late = late;
        }

        cout << max_late << "\n";
    }

    return 0;
}