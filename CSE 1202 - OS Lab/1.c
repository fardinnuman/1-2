#include <stdio.h>

int main()
{
    int arr[100], n, i, pos, val, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("~Linear Array Operations~");
        printf("1. Traversal\n2.Insertion\n3.Deletion\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Array elements: ");
            for (i = 0; i < n; i++)
            {
                printf("%d", arr[i]);
            }
            printf("\n");
            break;

        case 2:
        printf("Enter position (0 to %d): ", n);
        scanf("%d", &pos);
        printf("Enter value to insert: ",);
        scanf("%d", &val);

        if(pos)

        default:
            break;
        }
    }

    return 0;
}