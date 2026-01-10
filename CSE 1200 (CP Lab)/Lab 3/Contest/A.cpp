#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int score, max, min;
    int maxCount = 0, minCount = 0;

    cin >> score;
    max = min = score;

    for (int i = 1; i < n; i++)
    {
        cin >> score;
        if (score > max)
        {
            max = score;
            maxCount++;
        }
        else if (score < min)
        {
            min = score;
            minCount++;
        }
    }

    cout << maxCount << " " << minCount << endl;

    return 0;
}
