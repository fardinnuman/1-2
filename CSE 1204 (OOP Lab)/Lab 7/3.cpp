#include <iostream>
#include <string>
using namespace std;

class Patient
{
    string pname;
    int age;

public:
    Patient(string n, int a) : pname(n), age(a) {}
    void display()
    {
        cout << "Patient Name: " << pname << ", Age: " << age << endl;
    }
};

class Doctor{
    string dname;
    int experience;
    Patient p; // Composition: Patient is a member object of Doctor
public:
    Doctor(string dn, int exp, string pn, int pa) : dname(dn), experience(exp), p(pn, pa) {}
    void show()
    {
        cout << "Doctor Name: " << dname << ", Experience: " << experience << " years" << endl;
    }
    void treat()
    {
        cout << dname << " is treating ";
        p.display();
    }
};

int main()
{
    Doctor d1("Dr. Shyla", 15, "Numan", 20);
    d1.show();
    d1.treat();

    return 0;
}
