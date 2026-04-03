#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else
        {
            if (st.empty())
                return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cin >> s;
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}

