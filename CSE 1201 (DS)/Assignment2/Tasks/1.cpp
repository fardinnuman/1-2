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

void printList(Node* head) {
    while (head) { cout << head->patientID << " "; head = head->next; }
    cout << endl;
}

int main() {
    Node* head = createLinkedList();
    cout << "Initial Linked List: ";
    printList(head);
    return 0;
}
