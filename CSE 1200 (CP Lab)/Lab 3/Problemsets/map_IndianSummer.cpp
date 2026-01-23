#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<pair<string, string>, int> leafCount;

    for (int i = 0; i < n; i++) {
        string species, color;
        cin >> species >> color;

        leafCount[{species, color}]++; 
    }

    cout << leafCount.size() << "\n";

    return 0;
}
