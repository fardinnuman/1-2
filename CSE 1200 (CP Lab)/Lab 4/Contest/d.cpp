#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    unordered_map<char, char> match = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    while (t--)
    {
        string s;
        cin >> s;

        stack<char> stk;
        bool ok = true;

        for (char ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stk.push(ch);
            }
            else
            {
                if (stk.empty() || stk.top() != match[ch])
                {
                    ok = false;
                    break;
                }
                stk.pop();
            }
        }

        if (!stk.empty()) ok = false;

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}

