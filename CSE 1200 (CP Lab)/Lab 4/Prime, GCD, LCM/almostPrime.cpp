#include <iostream>
using namespace std;

bool isAlmostPrime(int num)
{
    int count = 0;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
            while (num % i == 0)
                num /= i;
        }
    }
    if (num > 1)
        count++;
    return count == 2;
}

int main()
{
    int n;
    cin >> n;
    int result = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isAlmostPrime(i))
            result++;
    }
    cout << result << endl;
    return 0;
}
