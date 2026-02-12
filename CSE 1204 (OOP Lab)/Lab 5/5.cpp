#include <iostream>
#include <utility>
using namespace std;

int main()
{
    // i) Assign values using make_pair()
    pair<int, string> px = make_pair(10, "Rajshahi");

    // ii) Print int data member
    cout << "First element (int): " << px.first << endl;

    // iii) Print string data member
    cout << "Second element (string): " << px.second << endl;

    // iv) Modify first data member using get<>()
    get<0>(px) = 20;
    cout << "Modified first element: " << px.first << endl;

    // v) Declare another pair and swap
    pair<int, string> bx = make_pair(50, "Dhaka");
    px.swap(bx);

    cout << "After swap, px: (" << px.first << ", " << px.second << ")" << endl;
    cout << "After swap, bx: (" << bx.first << ", " << bx.second << ")" << endl;

    return 0;
}

