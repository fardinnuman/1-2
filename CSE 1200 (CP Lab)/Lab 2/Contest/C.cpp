#include <bits/stdc++.h>

using namespace std;

void separateNumbers(string s)
{
    int n = s.size();
    for (int len = 1; len <= n / 2; len++)
    {
        string firstStr = s.substr(0, len);
        if (firstStr[0] == '0')
            continue;
        long long first = stoll(firstStr), num = first;
        int idx = len;
        while (idx < n)
        {
            num++;
            string next = to_string(num);
            if (s.substr(idx, next.size()) != next)
                break;
            idx += next.size();
        }
        if (idx == n)
        {
            cout << "YES " << first << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        separateNumbers(s);
    }
    return 0;
}
