#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    set<char> letters(s.begin(), s.end());
    cout << (letters.size() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;
}
