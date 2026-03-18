#include <bits/stdc++.h>

using namespace std;

int main()
{
    // // VECTOR //

    // vector<int> v1;

    // v1.push_back(1);
    // v1.emplace_back(2); //  similar as push_back but FASTER
    // v1.emplace_back(2403179);

    // cout << v1[0] << endl;
    // cout << v1[1] << endl;
    // cout << v1[2] << endl;

    // // VECTOR + PAIR //

    // vector<pair<int, int>> v2;

    // v2.emplace_back(3, 4);
    // v2.emplace_back(5, 6);

    // cout << v2[0].first << " " << v2[0].second << endl;
    // cout << v2[1].first << " " << v2[1].second << endl;

    // vector<int> v3(5, 100); // size = 5, values = 100, 100, 100, 100, 100
    // //             ↑   ↑
    // //           Size Value

    // vector<int> v4(5); // size = 5, values = GARBAGE or 0, 0, 0, 0, 0

    // cout << v3[1] << endl;
    // cout << v4[1] << endl;

    // // VECTOR COPYING //

    // vector<int> v5(5, 1);
    // vector<int> v6(v5);

    // cout << v5[1] << endl;
    // cout << v6[1] << endl;

    // VECTOR ITERATING //

    // vector<int> v7;
    // v7.emplace_back(10);
    // v7.emplace_back(20);
    // v7.emplace_back(30);
    // v7.emplace_back(40);
    // v7.emplace_back(50);

    // vector<int>::iterator it = v7.begin();
    // cout << *(it) << " ";
    // it++;
    // cout << *(it) << " ";
    // it++;
    // cout << *(it) << " ";
    // it++;
    // cout << *(it) << " ";
    // it++;
    // cout << *(it) << " ";

    // vector<int>::iterator it = v7.end();
    // cout << *(it) << " "; // prints GARBAGE
    // it--;
    // cout << *(it) << " "; // prints last element

    // cout << v7.back();

    // [10, 20, 30, 40, 50] GARBAGE
    //  ↑                ↑     ↑
    // begin()         back() end()

    // begin() or end() => ITERATOR
    // back() => VALUE

    // VECTOR PRINTING //

    vector<int> v8 = {1, 2, 3, 4, 5};

    for (vector<int>::iterator it = v8.begin(); it != v8.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl;

    for (auto it = v8.begin(); it != v8.end(); it++) // auto = vector<int>::iterator
    {
        cout << *(it) << " ";
    }

    cout << endl;

    for (auto it : v8)
    {
        cout << it << " ";
    }

    return 0;
}
