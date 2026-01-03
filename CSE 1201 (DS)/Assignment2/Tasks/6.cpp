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

Node* removeEvenPatients(Node* head) {
    while (head && head->patientID % 2 == 0) head = head->next;
    Node* current = head;
    while (current && current->next) {
        if (current->next->patientID % 2 == 0)
            current->next = current->next->next;
        else
            current = current->next;
    }
    return head;
}

void printList(Node* head) {
    while (head) { cout << head->patientID << " "; head = head->next; }
    cout << endl;
}

int main() {
    Node* head = createLinkedList();
    head = removeEvenPatients(head);
    cout << "Linked List after removing even patients: ";
    printList(head);
    return 0;
}
