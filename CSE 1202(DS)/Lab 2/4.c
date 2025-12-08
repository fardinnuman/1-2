#include <stdio.h>

int main()
{
    int arr[100], n, pos, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter position to split (1 to                       %d): ", n - 1);
    scanf("%d", &pos);

    printf("First part: ");
    for (i = 0; i < pos; i++)
        printf("%d ", arr[i]);

    printf("\nSecond part: ");
    for (i = pos; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
