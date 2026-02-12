#include <iostream>
using namespace std;

int main()
{
    int i;
    int ax[5] = {10, 20, 60, 40, 30};

    try
    {
        cout << "Enter index: ";
        cin >> i;
        if (i < 0 || i >= 5)
            throw i; // First catch block for integer
        cout << "ax[" << i << "] = " << ax[i] << endl;
    }
    catch (int e)
    {
        cout << "Exception caught: Invalid index " << e << endl;
    }
    catch (const char *msg)
    {
        cout << "Exception caught: " << msg << endl;
    }
    catch (...)
    {
        cout << "Unknown exception caught" << endl;
    }

    return 0;
}
