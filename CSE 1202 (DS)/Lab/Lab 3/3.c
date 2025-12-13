#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int val, int pos) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* ptr = head;
    for (int i = 0; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

void traverse() {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    insert(10, 0);
    insert(20, 1);
    insert(30, 1);

    traverse();

    return 0;
}
