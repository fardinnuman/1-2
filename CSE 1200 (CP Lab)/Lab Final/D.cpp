#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--){
        int N;
        cin >> N;
        vector<int>arr(N), mango(N, 1);

        for (int i=0;i<N;i++){
            cin >> arr[i];
        }    

        for (int i=0;i<N;i++){
            if (arr[i]>arr[i-1]){
                mango[i]=mango[i-1]+1;
            }    
        }

        for (int i=N-2;i>=0;i--){
            if (arr[i]>arr[i+1]){
                mango[i]=max(mango[i], mango[i+1]+1);
            }    
        }

        int sum=0;
        for (int i=0;i<N;i++){
            sum=sum+mango[i];
        }
        cout << sum << "\n";
    }
}