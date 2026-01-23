#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    vector<char> v1, v2;

    for (char c : s1)
        v1.push_back(tolower(c));
    for (char c : s2)
        v2.push_back(tolower(c));

    if (v1 < v2)
        cout << -1 << "\n";
    else if (v1 > v2)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";

    return 0;
}
