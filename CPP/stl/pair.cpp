#include <bits/stdc++.h>

using namespace std;

int main()
{
    pair<int, int> p1 = {1, 2};
    cout << p1.first << endl;
    cout << p1.second << endl;

    cout << endl;

    pair<int, pair<int, int>> p2 = {3, {4, 5}};
    cout << p2.first << endl;
    cout << p2.second.first << endl;
    cout << p2.second.second << endl;

    cout << endl;

    pair<int, int> arr[] = {{6, 7}, {8, 9}, {10, 11}};
    cout << arr[0].first << endl;
    cout << arr[0].second << endl;
    cout << arr[1].first << endl;
    cout << arr[1].second << endl;
    cout << arr[2].first << endl;
    cout << arr[2].second << endl;

    return 0;
}