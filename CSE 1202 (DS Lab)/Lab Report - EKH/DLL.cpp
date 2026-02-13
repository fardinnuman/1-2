#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = nullptr;

// Traverse in Doubly Linked List
void traverse()
{
    Node *ptr = head;
    if (ptr == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    cout << "Forward: ";
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        if (ptr->next == nullptr)
            break;
        ptr = ptr->next;
    }
    cout << "\nBackward: ";
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }
    cout << "\n";
}

// Search in Doubly Linked List
void search(int key)
{
    Node *ptr = head;
    int pos = 0;
    bool found = false;
    while (ptr != nullptr)
    {
        if (ptr->data == key)
        {
            cout << "Element " << key << " found at position " << pos << "\n";
            found = true;
            break;
        }
        ptr = ptr->next;
        pos++;
    }
    if (!found)
        cout << "Element " << key << " not found\n";
}

// Insert at end of Doubly Linked List
void insertEnd(int val)
{
    Node *newNode = new Node{val, nullptr, nullptr};
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *ptr = head;
    while (ptr->next != nullptr)
        ptr = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
}

// Delete from end of Doubly Linked List
void deleteEnd()
{
    if (!head)
    {
        cout << "List is empty\n";
        return;
    }
    Node *ptr = head;
    if (!ptr->next)
    {
        delete head;
        head = nullptr;
        return;
    }
    while (ptr->next != nullptr)
        ptr = ptr->next;
    ptr->prev->next = nullptr;
    delete ptr;
}

int main()
{
    int choice, val, key;
    while (true)
    {
        cout << "\n~~~ Doubly Linked List Operations ~~~\n";
        cout << "1. Traversal\n2. Search\n3. Insert at End\n4. Delete from End\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            cout << "Enter element to search: ";
            cin >> key;
            search(key);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> val;
            insertEnd(val);
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice! Try again\n";
        }
    }
}

