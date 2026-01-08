#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double n, m, a;

    cin >> n >> m >> a;

    double stone_length = ceil(n / a);
    double stone_width = ceil(m / a);
    long long stone_no = stone_length * stone_width;

    cout << stone_no << endl;

    return 0;
}