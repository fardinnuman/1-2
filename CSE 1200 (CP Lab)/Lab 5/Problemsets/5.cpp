#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[3005];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ans)
        {
            ans++;
        }
        else
        {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}

