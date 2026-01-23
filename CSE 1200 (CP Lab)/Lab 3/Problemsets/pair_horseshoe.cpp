#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> colors(4);
    for(int i = 0; i < 4; i++) {
        cin >> colors[i];
    }

    vector<pair<int,int>> shoes;
    for(int i = 0; i < 4; i++) {
        shoes.push_back({colors[i], i});
    }

    sort(shoes.begin(), shoes.end());

    int duplicates = 0;
    for(int i = 0; i < 3; i++) {
        if(shoes[i].first == shoes[i+1].first) {
            duplicates++;
        }
    }

    cout << duplicates << "\n";

    return 0;
}
