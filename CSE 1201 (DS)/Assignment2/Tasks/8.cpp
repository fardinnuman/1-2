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

Node* searchCriticalAdjacent(Node* head) {
    Node* current = head;
    while (current && current->next) {
        if (current->patientID % 2 != 0 && current->next->patientID % 2 == 0)
            return current;
        current = current->next;
    }
    return nullptr;
}

int main() {
    Node* head = createLinkedList();
    Node* found = searchCriticalAdjacent(head);
    if (found)
        cout << "Critical patient with normal adjacent: " << found->patientID << endl;
    else
        cout << "No such patient found." << endl;
    return 0;
}
