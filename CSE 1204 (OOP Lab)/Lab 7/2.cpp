#include <iostream>
#include <string>
using namespace std;

class Doctor {
private:
    string name;
    string specialization;

public:
    Doctor(string n, string s) {
        name = n;
        specialization = s;
    }

    void showDoctor() {
        cout << "Doctor Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
    }
};

class Patient {
private:
    string patientName;
    Doctor* doctor;

public:
    Patient(string pName, Doctor* d) {
        patientName = pName;
        doctor = d;
    }

    void showPatient() {
        cout << "Patient Name: " << patientName << endl;
        cout << "Consulting Doctor Details:" << endl;
        doctor->showDoctor();
    }
};

int main() {
    Doctor d1("Dr. Rahman", "Cardiology");

    Patient p1("Ali", &d1);
    p1.showPatient();

    cout << "\nDoctor still exists independently:\n";
    d1.showDoctor();

    return 0;
}
