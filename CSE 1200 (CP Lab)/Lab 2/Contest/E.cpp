#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[i] = a[i];
    }
    sort(s, s + n);

    int l = 0, r = n - 1;
    while (l < n && a[l] == s[l])
        l++;
    while (r >= 0 && a[r] == s[r])
        r--;

    if (l > r)
    {
        cout << "yes\n";
        return 0;
    }
    swap(a[l], a[r]);
    bool ok = true;
    for (int i = 0; i < n; i++)
        if (a[i] != s[i])
            ok = false;
    if (ok)
    {
        cout << "yes\nswap " << l + 1 << " " << r + 1 << endl;
        return 0;
    }
    swap(a[l], a[r]);

    reverse(a + l, a + r + 1);
    ok = true;
    for (int i = 0; i < n; i++)
        if (a[i] != s[i])
            ok = false;
    if (ok)
        cout << "yes\nreverse " << l + 1 << " " << r + 1 << endl;
    else
        cout << "no\n";

    return 0;
}
