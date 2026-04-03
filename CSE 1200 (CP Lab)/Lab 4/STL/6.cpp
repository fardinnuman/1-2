#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++)
        cin >> pairs[i].first >> pairs[i].second;

    sort(pairs.begin(), pairs.end());
    for (auto &p : pairs)
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    return 0;
}

