#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    string command;

    while (true)
    {
        cin >> command;
        if (command == "ENQUEUE")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (command == "DEQUEUE")
        {
            if (!q.empty())
                q.pop();
        }
        else if (command == "FRONT")
        {
            if (!q.empty())
                cout << q.front() << endl;
        }
        else if (command == "SIZE")
            cout << q.size() << endl;
        else if (command == "EXIT")
            break;
    }

    return 0;
}
