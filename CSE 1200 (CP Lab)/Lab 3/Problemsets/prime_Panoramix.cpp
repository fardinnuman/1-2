#include <iostream>
using namespace std;

bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int nextPrime = n + 1;
    while (!isPrime(nextPrime))
    {
        nextPrime++;
    }

    if (nextPrime == m)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
