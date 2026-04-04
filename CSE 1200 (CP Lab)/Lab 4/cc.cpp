#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;

                string key = "";
                for (int k = 0; k < 5; k++)
                {
                    key += char(freq[k] + '0');
                }

                mp[key]++;
            }
        }

        int ans = 0;
        for (auto x : mp)
        {
            int c = x.second;
            ans += c * (c - 1) / 2;
        }

        cout << ans << endl;
    }

    return 0;
}