#include <iostream>
#include <tuple>
using namespace std;

int main()
{
    // i) Assign values using make_tuple()
    tuple<int, string, double> tx = make_tuple(100, "Fardin", 3.5);

    // ii) Print int data member
    cout << "Integer element: " << get<0>(tx) << endl;

    // iii) Print string data member
    cout << "String element: " << get<1>(tx) << endl;

    // iv) Print double data member
    cout << "Double element: " << get<2>(tx) << endl;

    // v) Modify third data member to 3.7
    get<2>(tx) = 3.7;
    cout << "Modified double element: " << get<2>(tx) << endl;

    // vi) Declare another tuple and swap
    tuple<int, string, double> bx = make_tuple(200, "Numan", 4.2);
    tx.swap(bx);

    cout << "After swap, tx: (" << get<0>(tx) << ", " << get<1>(tx) << ", " << get<2>(tx) << ")" << endl;
    cout << "After swap, bx: (" << get<0>(bx) << ", " << get<1>(bx) << ", " << get<2>(bx) << ")" << endl;

    return 0;
}

