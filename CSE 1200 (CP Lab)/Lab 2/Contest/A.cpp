#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int grades[n];
    for (int i = 0; i < n; i++)
    {
        cin >> grades[i];
    }
    for (int i = 0; i < n; i++)
    {

        int grade = grades[i];

        if (grade < 38)
        {
            cout << grade << endl;
        }

        else
        {
            int after = ((grade / 5) + 1) * 5;
            int difference = after - grade;

            if (difference < 3)
            {
                cout << after << endl;
            }
            else
            {
                cout << grade << endl;
            }
        }
    }
    return 0;
}