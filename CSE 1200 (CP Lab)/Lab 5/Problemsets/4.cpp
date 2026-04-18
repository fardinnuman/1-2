#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 2)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << 1 << " ";
        }
        cout << endl;
    }
    else
    {
        cout << 2 << endl;

        for (int i = 2; i <= n + 1; i++)
        {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 2 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

