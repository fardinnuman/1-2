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

Node* rearrangeOddEven(Node* head) {
    Node *oddHead = nullptr, *oddTail = nullptr;
    Node *evenHead = nullptr, *evenTail = nullptr;
    Node* current = head;
    while (current) {
        if (current->patientID % 2 != 0) {
            if (!oddHead) oddHead = oddTail = current;
            else { oddTail->next = current; oddTail = current; }
        } else {
            if (!evenHead) evenHead = evenTail = current;
            else { evenTail->next = current; evenTail = current; }
        }
        current = current->next;
    }
    if (oddTail) oddTail->next = evenHead;
    if (evenTail) evenTail->next = nullptr;
    return oddHead ? oddHead : evenHead;
}

void printList(Node* head) {
    while (head) { cout << head->patientID << " "; head = head->next; }
    cout << endl;
}

int main() {
    Node* head = createLinkedList();
    head = rearrangeOddEven(head);
    cout << "After rearranging odd first: ";
    printList(head);
    return 0;
}
