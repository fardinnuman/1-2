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

int sumLinkedList(Node* head) {
    int sum = 0;
    while (head) { sum += head->patientID; head = head->next; }
    return sum;
}

int main() {
    Node* head = createLinkedList();
    cout << "Sum of patient IDs: " << sumLinkedList(head) << endl;
    return 0;
}
