// O(n^2)

#include <iostream>

using namespace std;

int main() {
    int arr[] = {3, 6, 1, 8, 4};
    int n = 5;

    int pivot = arr[4];  
    int i = -1;
    for(int j=0; j<4; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[4]);

    pivot = arr[1];
    int k = -1;
    for(int j=0; j<=1; j++){
        if(arr[j] <= pivot){
            k++;
            swap(arr[k], arr[j]);
        }
    }
    swap(arr[k+1], arr[1]);

    for(int i=0;i<n;i++) cout << arr[i] << " ";
}

