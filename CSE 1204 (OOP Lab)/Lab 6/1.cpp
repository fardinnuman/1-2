#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    int choice, value;

    do{
        cout << "\n** Stack **\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display top element\n";
        cout << "4. Exit\n";
        cout << "Enter your option: ";
        cin >> choice;

        switch (choice){
        case 1: // Push
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2: // Pop
            if (!s.empty()){
                cout << "Popped: " << s.top() << endl;
                s.pop();
            }
            else
                cout << "Stack is empty. Cannot pop.\n";
            break;

        case 3: // Display top
            if (!s.empty())
                cout << "Top element: " << s.top() << endl;
            else
                cout << "Stack is empty.\n";
            break;

        case 4: // Exit
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid option! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}


