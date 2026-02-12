#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 6> ax;

    // i) Assign values using single statement
    ax = {10, 60, 30, 70, 20, 0};

    // ii) Print third element using at()
    cout << "Third element: " << ax.at(2) << endl;

    // iii) Print first element using front()
    cout << "First element: " << ax.front() << endl;

    // iv) Print last element using back()
    cout << "Last element: " << ax.back() << endl;

    // v) Fill array elements with a specific value
    ax.fill(5);
    cout << "Array after fill: ";
    for (int i = 0; i < ax.size(); i++)
        cout << ax[i] << " ";
    cout << endl;

    // vi) Check whether array is empty
    if (ax.empty())
        cout << "Array is empty" << endl;
    else
        cout << "Array is not empty" << endl;

    // vii) Print size of array
    cout << "Size of array: " << ax.size() << endl;

    // viii) Print maximum size of array
    cout << "Maximum size: " << ax.max_size() << endl;

    // ix) Print address of first element
    cout << "Address of first element: " << ax.begin() << endl;

    // x) Print address of last element
    cout << "Address of last element: " << ax.end() << endl;

    return 0;
}

