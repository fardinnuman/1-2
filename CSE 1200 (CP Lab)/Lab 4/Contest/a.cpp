#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int A[n], B[n];

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    sort(A, A + n);
    sort(B, B + n);

    int i = 0, j = 0;
    int matches = 0;

    while (i < n && j < n)
    {
        if (A[i] == B[j])
        {
            matches++;
            i++;
            j++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    if (matches == n)
    {
        cout << matches - 1 << endl;
    }
    else
    {
        cout << matches + 1 << endl;
    }
    return 0;
}
