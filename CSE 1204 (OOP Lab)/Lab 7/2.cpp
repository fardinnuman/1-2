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
    Patient(string p, Doctor* d) {
        patientName = p;
        doctor = d;
    }

    void showPatient() {
        cout << "Patient Name: " << patientName << endl;
        doctor->showDoctor();
    }
};

int main() {
    Doctor d1("Dr. Fardin Numan", "Moner Doctor");

    Patient p1("Mahdi", &d1);
    p1.showPatient();

    cout << "\nPatient destroyed, Doctor still exists:\n";
    d1.showDoctor();

    return 0;
}
