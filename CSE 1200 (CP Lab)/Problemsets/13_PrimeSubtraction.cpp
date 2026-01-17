#include <iostream>

using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long x, y;
        cin >> x;
        cin >> y;

        long long diff = x - y;
        if (diff >= 2){
            cout << "YES" << endl;
        }
        else if (diff == 1){
            cout << "NO" << endl;
        }
    }

    return 0;
}