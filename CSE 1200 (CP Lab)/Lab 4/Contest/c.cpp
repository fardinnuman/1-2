#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;

    map<string, int> marks;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            string name;
            int score;
            cin >> name >> score;
            marks[name] += score;
        }
        else if (type == 2)
        {
            string name;
            cin >> name;
            marks[name] = 0;
        }
        else if (type == 3)
        {
            string name;
            cin >> name;
            cout << marks[name] << endl;
        }
    }

    return 0;
}