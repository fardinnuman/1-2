#include <iostream>
using namespace std;

int fine(int day, int month, int year, int dayy, int monthh, int yearr)
{

    if (year > yearr)
    {
        return 10000;
    }
    if (year == yearr && month > monthh)
    {
        return 500 * (month - monthh);
    }
    if (year == yearr && month == monthh && day > dayy)
    {
        return 15 * (day - dayy);
    }
    return 0;
}

int main()
{
    int day, month, year;
    int dayy, monthh, yearr;

    cin >> day >> month >> year;
    cin >> dayy >> monthh >> yearr;
    cout << fine(day, month, year, dayy, monthh, yearr) << endl;

    return 0;
}
