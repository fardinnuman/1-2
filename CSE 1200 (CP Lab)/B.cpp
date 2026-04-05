#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        int n;
        int sum = 0;
        int largest = -68;

        for (int i = 0; i < 7; i++)
        {
            cin >> n;
            sum += n;
            largest = max(largest, n);
        }

        int maxSum = -sum + 2 * largest;
        cout << maxSum << "\n";
    }
}