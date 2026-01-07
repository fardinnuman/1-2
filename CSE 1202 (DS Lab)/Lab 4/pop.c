// 3

#include <stdio.h>
#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int choice, val;

    while (1) {
        printf("\nStack Operations\n");
        printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) { 
            if (top == MAX - 1) {
                printf("Stack Overflow! Cannot push element.\n");
            } else {
                printf("Enter value to push: ");
                scanf("%d", &val);
                top++;
                stack[top] = val;
                printf("Element %d pushed successfully.\n", val);
            }
        } else if (choice == 2) { 
            if (top == -1) {
                printf("Stack Underflow! No elements to pop.\n");
            } else {
                printf("Element %d popped from stack.\n", stack[top]);
                top--;
            }
        } else if (choice == 3) { 
            if (top == -1) {
                printf("Stack is empty.\n");
            } else {
                printf("Stack elements (Top to Bottom): ");
                for (int i = top; i >= 0; i--) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
            }
        } else if (choice == 4) { 
            break;
        } else {                                                                                                                                                                                                                               
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
