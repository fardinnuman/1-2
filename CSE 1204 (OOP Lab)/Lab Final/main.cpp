#include <bits/stdc++.h>
using namespace std;

class Unit
{
public:
    int x;

    void missionReport()
    {
        cout << "Mission Report of Unit Class";
    }

    Unit()
    {
        cout << "Default Constructor";
    }

    Unit(int x)
    {
        this->x = x;

        cout << "Parameterized Constructor";
    }

    Unit(const int &obj)
    {
        cout << "Copy Constructor";
    }

    ~Unit()
    {

        cout << "Unit Destroyed";
    }
};

class AirforceUnit : public Unit
{
public:
    AirforceUnit()
    {
        cout << "Default Constructor of AirforceUnit";
    }

    AirforceUnit(int x)
    {
        this->x = x;

        cout << "Parameterized Constructor of AirforceUnit";
    }

    AirforceUnit(const int &obj)
    {
        cout << "Copy Constructor of AirforceUnit";
    }

    void missionReport()
    {

        cout << "Mission Report of AirforceUnit Class";
    }

    ~AirforceUnit()
    {

        cout << "AirforceUnit Unit Destroyed";
    }
};

class NavalUnit : public Unit
{
public:
    NavalUnit()
    {
        cout << "Default Constructor of NavalUnit";
    }

    NavalUnit(int x)
    {
        this->x = x;

        cout << "Parameterized Constructor of NavalUnit";
    }

    void missionReport()
    {
        cout << "Mission Report of NavalUnit Class";
    }

    ~NavalUnit()
    {

        cout << "NavalUnit Unit Destroyed";
    }
};

class StrikeCommand : public AirforceUnit, public NavalUnit
{

public:
    StrikeCommand()
    {
        cout << "Default Constructor of StrikeCommand";
    }

    StrikeCommand(int x)
    {
        this->x = x;

        cout << "Parameterized Constructor of StrikeCommand";
    }

    void missionReport()
    {
        cout << "Mission Report of StrikeCommand Class";
    }

    ~StrikeCommand()
    {

        cout << "NavalUnit Unit Destroyed";
    }
};

int main()
{
    StrikeCommand ob1;
    StrikeCommand ob2;
    StrikeCommand ob3;
    StrikeCommand ob4;
    StrikeCommand ob5;
    ob1.missionReport();

    return 0;
}
