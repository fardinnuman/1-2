#include <iostream>
#include <string>
using namespace std;

struct Food {
    string name;
    double price;
};

int main() {
    const int SIZE = 5;
    Food menu[SIZE] = {
        {"Burger", 600.0},
        {"Pizza", 850.0},
        {"Pasta", 725.0},
        {"Salad", 450.0},
        {"Soda", 200.0}
    };

    int order[SIZE] = {0};
    int choice;
    double total = 0.0;

    cout << "=== Welcome to FastFood Restaurant ===\n";

    do {
        cout << "\nMenu:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i + 1 << ". " << menu[i].name << " - BDT " << menu[i].price << endl;
        }
        cout << SIZE + 1 << ". Checkout & Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= SIZE) {
            int qty;
            cout << "Enter quantity for " << menu[choice - 1].name << ": ";
            cin >> qty;

            order[choice - 1] += qty;
            total += menu[choice - 1].price * qty;
            cout << qty << " " << menu[choice - 1].name << "(s) added to your order.\n";
        } else if (choice == SIZE + 1) {
            cout << "\n=== Your Order ===\n";
            for (int i = 0; i < SIZE; i++) {
                if (order[i] > 0) {
                    cout << menu[i].name << " x " << order[i] 
                         << " = BDT " << menu[i].price * order[i] << endl;
                }
            }
            cout << "Total Amount: BDT " << total << endl;
            cout << "Thank you for ordering!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (true);

    return 0;
}
