#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int sum = 0;
    
    cout << "Enter 5 numbers: ";
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "Sum = " << sum << endl;
    return 0;
}
