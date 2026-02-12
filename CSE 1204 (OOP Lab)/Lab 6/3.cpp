#include <iostream>
#include <vector>
#include <algorithm> // for find()
using namespace std;

int main() {
    vector<int> v;
    int choice, value, pos;

    do {
        cout << "\n** Linked List **\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Update\n";
        cout << "4. Search\n";
        cout << "5. Exit\n";
        cout << "Enter your option: ";
        cin >> choice;

        switch(choice) {
            case 1: // Insert
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position (0-based index, use -1 to insert at end): ";
                cin >> pos;
                if(pos == -1 || pos == v.size())
                    v.push_back(value);
                else if(pos >= 0 && pos < v.size())
                    v.insert(v.begin() + pos, value);
                else
                    cout << "Invalid position!\n";
                break;

            case 2: // Delete
                cout << "Enter position to delete: ";
                cin >> pos;
                if(pos >= 0 && pos < v.size())
                    v.erase(v.begin() + pos);
                else
                    cout << "Invalid position!\n";
                break;

            case 3: // Update
                cout << "Enter position to update: ";
                cin >> pos;
                if(pos >= 0 && pos < v.size()) {
                    cout << "Enter new value: ";
                    cin >> value;
                    v[pos] = value;
                } else {
                    cout << "Invalid position!\n";
                }
                break;

            case 4: // Search
                cout << "Enter value to search: ";
                cin >> value;
                {
                    auto it = find(v.begin(), v.end(), value);
                    if(it != v.end())
                        cout << "Value found at position " << distance(v.begin(), it) << endl;
                    else
                        cout << "Value not found!\n";
                }
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid option! Try again.\n";
        }

        // Display current vector
        cout << "Current List: ";
        for(int x : v) cout << x << " ";
        cout << endl;

    } while(choice != 5);

    return 0;
}

