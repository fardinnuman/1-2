#include <iostream>
using namespace std;

// Node structure for Circular Linked List
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = nullptr;

// Traverse in Circular Linked List
void traverse()
{
    if (!head)
    {
        cout << "List is empty\n";
        return;
    }
    Node *ptr = head;
    cout << "Forward: ";
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << "\nBackward: ";
    ptr = head->prev; // start from last node
    Node *start = ptr;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->prev;
    } while (ptr != start);
    cout << "\n";
}

// Search in Circular Linked List
void search(int key)
{
    if (!head)
    {
        cout << "List is empty\n";
        return;
    }
    Node *ptr = head;
    int pos = 0;
    bool found = false;
    do
    {
        if (ptr->data == key)
        {
            cout << "Element " << key << " found at position " << pos << "\n";
            found = true;
            break;
        }
        ptr = ptr->next;
        pos++;
    } while (ptr != head);
    if (!found)
        cout << "Element " << key << " not found\n";
}

// Insert at end of Circular Linked List
void insertEnd(int val)
{
    Node *newNode = new Node{val, nullptr, nullptr};
    if (!head)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }
    Node *tail = head->prev; // last node
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

// Delete from end of Circular Linked List
void deleteEnd()
{
    if (!head)
    {
        cout << "List is empty\n";
        return;
    }
    if (head->next == head)
    { // only one node
        delete head;
        head = nullptr;
        return;
    }
    Node *tail = head->prev;
    tail->prev->next = head;
    head->prev = tail->prev;
    delete tail;
}

int main()
{
    int choice, val, key;
    while (true)
    {
        cout << "\n~~~ Circular Linked List Operations ~~~\n";
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
