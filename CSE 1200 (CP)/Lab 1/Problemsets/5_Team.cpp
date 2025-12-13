#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a + b + c >= 2)
            count++;
    }
    cout << count << endl;
}
