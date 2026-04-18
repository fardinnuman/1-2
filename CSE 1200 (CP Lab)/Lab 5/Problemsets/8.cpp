#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int h[150005];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int current_sum = 0;
    for (int i = 0; i < k; i++)
    {
        current_sum += h[i];
    }

    int min_sum = current_sum;
    int min_index = 1;

    for (int i = k; i < n; i++)
    {
        current_sum = current_sum - h[i - k] + h[i];

        if (current_sum < min_sum)
        {
            min_sum = current_sum;
            min_index = i - k + 2;
        }
    }

    cout << min_index << endl;

    return 0;
}

