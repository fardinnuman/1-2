#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int x;
        cin >> x;

        if (x < 67)
        {
            cout << x + 1 << "\n";
        }

        else
        {
            cout << 67 << "\n";
        }
    }

    return 0;
}