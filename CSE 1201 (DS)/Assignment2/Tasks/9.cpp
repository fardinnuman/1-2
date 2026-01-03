#include <iostream>
using namespace std;

struct Node {
    int patientID;
    Node* next;
};

struct DNode {
    int patientID;
    DNode* prev;
    DNode* next;
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

DNode* convertToDoubly(Node* head) {
    if (!head) return nullptr;
    DNode* dHead = new DNode{ head->patientID, nullptr, nullptr };
    DNode* prev = dHead;
    Node* current = head->next;

    while (current) {
        DNode* temp = new DNode{ current->patientID, prev, nullptr };
        prev->next = temp;
        prev = temp;
        current = current->next;
    }
    return dHead;
}

void printDoubly(DNode* head) {
    while (head) {
        cout << head->patientID << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = createLinkedList();
    DNode* dHead = convertToDoubly(head);
    cout << "Doubly linked list: ";
    printDoubly(dHead);
    return 0;
}
