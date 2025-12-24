#include <bits/stdc++.h>

using namespace std;

string larrysArray(int A[], int n)
{
    int inv = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i] > A[j])
                inv++;
    return (inv % 2 == 0) ? "YES" : "NO";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << larrysArray(A, n) << endl;
    }
    return 0;
}
