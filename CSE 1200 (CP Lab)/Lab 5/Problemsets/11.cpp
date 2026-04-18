#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long freq[100005] = {0};
    int max_val = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
        max_val = max(max_val, x);
    }

    long long dp[100005] = {0};
    dp[1] = freq[1] * 1;

    for (int i = 2; i <= max_val; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + freq[i] * i);
    }

    cout << dp[max_val] << endl;

    return 0;
}

