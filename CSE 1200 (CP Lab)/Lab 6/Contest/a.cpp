#include <bits/stdc++.h>
using namespace std;

int main()
{
    int total, max;
    cin >> total >> max;

    vector<int> important;
    int luck = 0;

    for (int i = 0; i < total; i++)
    {
        int value, flag;
        cin >> value >> flag;

        if (flag == 0)
        {
            luck += value;
        }
        else
        {
            important.push_back(value);
        }
    }

    sort(important.begin(), important.end(), greater<int>());

    for (int i = 0; i < important.size(); i++)
    {
        if (i < max)
        {
            luck += important[i];
        }
        else
        {
            luck -= important[i];
        }
    }

    cout << luck << endl;

    return 0;
}
