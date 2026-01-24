// O(n^2)

#include <iostream>

using namespace std;

void quickSort(int arr[], int left, int right) {
    if(left >= right) return;  // base case

    int pivot = arr[right];    // choose last element as pivot
    int i = left - 1;

    for(int j = left; j < right; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);

    quickSort(arr, left, i);       // sort left part
    quickSort(arr, i + 2, right);  // sort right part
}

int main() {
    int arr[] = {3, 6, 1, 8, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

