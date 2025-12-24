#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int hmax = 0;
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        int h;

        cin >> h;
        if (h > hmax)
        {
            hmax = h;
            count = 1;
        }
        else if (h == hmax)
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}