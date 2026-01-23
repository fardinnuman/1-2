#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string result = "";

    for (char c : s)
    {
        if (!result.empty() && result.back() == c)
        {
            result.pop_back();
        }
        else
        {
            result.push_back(c);
        }
    }

    cout << result << "\n";
    return 0;
}
