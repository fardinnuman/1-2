#include <iostream>
using namespace std;

struct Node {
    int patientID;
    Node* next;
};

Node* createLinkedList() {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 1; i <= 20; i++) {
        Node* newNode = new Node{ i, nullptr };
        if (!head) head = tail = newNode;
        else { tail->next = newNode; tail = newNode; }
    }
    return head;
}

Node* sortLinkedList(Node* head) {
    if (!head) return nullptr;
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) {
            if (current->patientID > current->next->patientID) {
                swap(current->patientID, current->next->patientID);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
    return head;
}

void printList(Node* head) {
    while (head) { cout << head->patientID << " "; head = head->next; }
    cout << endl;
}

int main() {
    Node* head = createLinkedList();
    head = sortLinkedList(head);
    cout << "Sorted Linked List: ";
    printList(head);
    return 0;
}
