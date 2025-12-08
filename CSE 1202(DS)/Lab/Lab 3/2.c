#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void search(int key) {
    struct Node* ptr = head;
    int pos = 0;

    while (ptr != NULL) {
        if (ptr->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    printf("Element %d not found.\n", key);
}

int main() {
    head = malloc(sizeof(struct Node));
    head->data = 5;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 15;
    head->next->next = NULL;

    search(15);
    search(100);

    return 0;
}
