#include <iostream>
using namespace std;

int main() {
    int n;
    do {
        cout << "Enter a number (0 to stop): ";
        cin >> n;
    } while(n != 0);
    cout << "Finished!" << endl;
    return 0;
}
