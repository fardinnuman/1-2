#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty()) break;

                if ((c == ')' && st.top() == '(') ||
                    (c == '}' && st.top() == '{') ||
                    (c == ']' && st.top() == '['))
                    st.pop();
                else
                    break;
            }
        }

        cout << (st.empty() ? "YES" : "NO") << endl;
    }
    return 0;
}
