#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    int choice, value;

    do{
        cout << "\n** Queue **\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Front\n";
        cout << "4. Display Rear\n";
        cout << "5. Exit\n";
        cout << "Enter your option: ";
        cin >> choice;

        switch (choice){
        case 1: // Enqueue
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.push(value);
            break;

        case 2: // Dequeue
            if (!q.empty()){
                cout << "Dequeued: " << q.front() << endl;
                q.pop();
            }
            else{
                cout << "Queue is empty. Cannot dequeue.\n";
            }
            break;

        case 3: // Display Front
            if (!q.empty())
                cout << "Front element: " << q.front() << endl;
            else
                cout << "Queue is empty.\n";
            break;

        case 4: // Display Rear
            if (!q.empty())
                cout << "Rear element: " << q.back() << endl;
            else
                cout << "Queue is empty.\n";
            break;

        case 5: // Exit
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid option! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
