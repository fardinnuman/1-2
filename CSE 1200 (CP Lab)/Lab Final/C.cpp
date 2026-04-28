#include <bits/stdc++.h>
using namespace std;

int main()
{
    int W, R, T, B;
    cin >> W >> R >> T >> B;

    int n;
    cin >> n;

    int water=W;
    int ttime=0;

    for (int i=0;i<n;i++){
        if (water<R){
            ttime=ttime+T;
            water=W;
        }
        water=water-R;
        ttime=ttime+B;
    }

    cout << ttime << endl;

    return 0;
}