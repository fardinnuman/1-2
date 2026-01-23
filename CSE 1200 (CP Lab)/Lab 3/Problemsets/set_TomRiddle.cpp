#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<string> seen;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        if (seen.count(name))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
            seen.insert(name);
        }
    }

    return 0;
}
