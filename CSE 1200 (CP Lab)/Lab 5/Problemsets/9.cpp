#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[100005];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max_len = 1;
    int current_len = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
        {
            current_len++;
            max_len = max(max_len, current_len);
        }
        else
        {
            current_len = 1;
        }
    }

    cout << max_len << endl;

    return 0;
}

