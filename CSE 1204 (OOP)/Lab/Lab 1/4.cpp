#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Structure to store Member data
struct Member {
    int id;
    float height; // in meters
    float weight; // in kg

    // Calculate BMI
    float calculateBMI() const {
        return weight / (height * height);
    }

    // Display BMI classification
    void displayBMI() const {
        float bmi = calculateBMI();
        cout << "Member ID: " << id << " | BMI: " << bmi << " | Classification: ";
        if (bmi < 16) cout << "Severe Thinness";
        else if (bmi < 17) cout << "Moderate Thinness";
        else if (bmi < 18.5) cout << "Mild Thinness";
        else if (bmi < 25) cout << "Normal";
        else if (bmi < 30) cout << "Overweight";
        else if (bmi < 35) cout << "Obese Class I";
        else if (bmi < 40) cout << "Obese Class II";
        else cout << "Obese Class III";
        cout << endl;
    }
};

// Global vector to store members
vector<Member> members;

// Function to add a member
void addMember() {
    Member m;
    cout << "Enter Member ID: ";
    cin >> m.id;
    cout << "Enter Height (m): ";
    cin >> m.height;
    cout << "Enter Weight (kg): ";
    cin >> m.weight;
    members.push_back(m);
    cout << "Member added successfully.\n";
}

// Function to update a member
void updateMember() {
    int id;
    cout << "Enter Member ID to update: ";
    cin >> id;
    for (auto &m : members) {
        if (m.id == id) {
            cout << "Enter new Height (m): ";
            cin >> m.height;
            cout << "Enter new Weight (kg): ";
            cin >> m.weight;
            cout << "Member updated successfully.\n";
            return;
        }
    }
    cout << "Member not found.\n";
}

// Function to remove a member
void removeMember() {
    int id;
    cout << "Enter Member ID to remove: ";
    cin >> id;
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->id == id) {
            members.erase(it);
            cout << "Member removed successfully.\n";
            return;
        }
    }
    cout << "Member not found.\n";
}

// Function to calculate max height and weight
void maxHeightWeight() {
    if (members.empty()) {
        cout << "No members available.\n";
        return;
    }
    float maxH = members[0].height;
    float maxW = members[0].weight;
    for (const auto &m : members) {
        if (m.height > maxH) maxH = m.height;
        if (m.weight > maxW) maxW = m.weight;
    }
    cout << "Max Height: " << maxH << " m | Max Weight: " << maxW << " kg\n";
}

// Function to calculate min height and weight
void minHeightWeight() {
    if (members.empty()) {
        cout << "No members available.\n";
        return;
    }
    float minH = members[0].height;
    float minW = members[0].weight;
    for (const auto &m : members) {
        if (m.height < minH) minH = m.height;
        if (m.weight < minW) minW = m.weight;
    }
    cout << "Min Height: " << minH << " m | Min Weight: " << minW << " kg\n";
}

// Function to calculate average height and weight
void averageHeightWeight() {
    if (members.empty()) {
        cout << "No members available.\n";
        return;
    }
    float sumH = 0, sumW = 0;
    for (const auto &m : members) {
        sumH += m.height;
        sumW += m.weight;
    }
    cout << "Average Height: " << sumH / members.size() << " m | Average Weight: " << sumW / members.size() << " kg\n";
}

// Function to display BMI of all members
void displayBMI() {
    if (members.empty()) {
        cout << "No members available.\n";
        return;
    }
    for (const auto &m : members) {
        m.displayBMI();
    }
}

int main() {
    int choice;
    do {
        cout << "\n********** Main Menu **********\n";
        cout << "1. Add Member\n";
        cout << "2. Update Member\n";
        cout << "3. Remove Member\n";
        cout << "4. Max Height and Weight\n";
        cout << "5. Min Height and Weight\n";
        cout << "6. Average Height and Weight\n";
        cout << "7. BMI Classification\n";
        cout << "8. Exit\n";
        cout << "Enter your option (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1: addMember(); break;
            case 2: updateMember(); break;
            case 3: removeMember(); break;
            case 4: maxHeightWeight(); break;
            case 5: minHeightWeight(); break;
            case 6: averageHeightWeight(); break;
            case 7: displayBMI(); break;
            case 8: cout << "Exiting program.\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
