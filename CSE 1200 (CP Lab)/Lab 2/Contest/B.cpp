#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int energy = 100;
    int position = 0;

    do
    {
        position = (position + k) % n;
        energy -= 1;

        if (c[position] == 1)
        {
            energy -= 2;
        }

    } while (position != 0);

    cout << energy << endl;

    return 0;
}

