#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;

        stack<char> st;
        bool balanced = true;

        for (char c : s)
        {

            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }

            else
            {
                if (st.empty())
                {
                    balanced = false;
                    break;
                }

                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '['))
                {
                    st.pop();
                }
                else
                {
                    balanced = false;
                    break;
                }
            }
        }

        if (balanced && st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
