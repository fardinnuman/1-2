#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> unique_set;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        unique_set.insert(num);
    }

    for (int num : unique_set)
        cout << num << " ";
    cout << "\nTotal unique elements: " << unique_set.size() << endl;
    return 0;
}

