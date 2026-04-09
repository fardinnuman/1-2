#include <bits/stdc++.h>
using namespace std;

class Unit
{
public:
    int x;

    void missionReport()
    {
        cout << "Mission Report of Unit Class" << endl;
    }

    Unit()
    {
        cout << "Default Constructor of Unit" << endl;
    }

    Unit(int x)
    {
        this->x = x;
        cout << "Parameterized Constructor of Unit" << endl;
    }

    Unit(const Unit &obj)
    {
        this->x = obj.x;
        cout << "Copy Constructor of Unit" << endl;
    }

    ~Unit()
    {
        cout << "Unit Destroyed" << endl;
    }
};

class AirforceUnit : public Unit
{
public:
    void missionReport()
    {
        cout << "Mission Report of AirforceUnit Class" << endl;
    }

    AirforceUnit()
    {
        cout << "Default Constructor of AirforceUnit" << endl;
    }

    AirforceUnit(int x)
    {
        this->x = x;
        cout << "Parameterized Constructor of AirforceUnit" << endl;
    }

    AirforceUnit(const AirforceUnit &obj)
    {
        this->x = obj.x;
        cout << "Copy Constructor of AirforceUnit" << endl;
    }

    ~AirforceUnit()
    {

        cout << "AirforceUnit Unit Destroyed" << endl;
    }
};

class NavalUnit : public Unit
{
public:
    void missionReport()
    {
        cout << "Mission Report of NavalUnit Class" << endl;
    }

    NavalUnit()
    {
        cout << "Default Constructor of NavalUnit" << endl;
    }

    NavalUnit(int x)
    {
        this->x = x;
        cout << "Parameterized Constructor of NavalUnit" << endl;
    }

    NavalUnit(const NavalUnit &obj)
    {
        this->x = obj.x;
        cout << "Copy Constructor of NavalUnit" << endl;
    }

    ~NavalUnit()
    {
        cout << "NavalUnit Unit Destroyed" << endl;
    }
};

class StrikeCommand : public AirforceUnit, public NavalUnit
{

public:
    void missionReport()
    {
        cout << "Mission Report of StrikeCommand Class" << endl;
    }

    StrikeCommand()
    {
        cout << "Default Constructor of StrikeCommand" << endl;
    }

    StrikeCommand(int x)
    {
        cout << "Parameterized Constructor of StrikeCommand" << endl;
    }

    StrikeCommand(const StrikeCommand &obj)
    {
        cout << "Copy Constructor of StrikeCommand" << endl;
    }

    ~StrikeCommand()
    {
        cout << "StrikeCommand Unit Destroyed" << endl;
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
