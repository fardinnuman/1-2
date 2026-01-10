#include <iostream>
using namespace std;

long long strangeCounter(long long t)
{
    long long start = 1;
    long long length = 3;
    while (t > (start + length - 1))
    {
        start = start + length;
        length = length * 2;
    }
    return length - (t - start);
}

int main()
{
    long long t;
    if (!(cin >> t))
    {
        return 0;
    }
    cout << strangeCounter(t) << endl;
    return 0;
}
