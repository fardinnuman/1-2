// 5

#include <stdio.h>
#define MAX 100

int q[MAX], f = -1, r = -1, cf = -1, cr = -1;

void enL(int x, int n)
{
    if (r == n - 1)
        printf("Overflow\n");
    else
    {
        if (f == -1)
            f = 0;
        q[++r] = x;
    }
}
void deL()
{
    if (f == -1 || f > r)
        printf("Underflow\n");
    else
        printf("Deleted %d\n", q[f++]);
}
void disL()
{
    if (f == -1 || f > r)
        printf("Empty\n");
    else
        for (int i = f; i <= r; i++)
            printf("%d ", q[i]);
    printf("\n");
}

void enC(int x, int n)
{
    if ((cr + 1) % n == cf)
        printf("Overflow\n");
    else
    {
        if (cf == -1)
            cf = 0;
        cr = (cr + 1) % n;
        q[cr] = x;
    }
}
void deC(int n)
{
    if (cf == -1)
        printf("Underflow\n");
    else
    {
        printf("Deleted %d\n", q[cf]);
        if (cf == cr)
            cf = cr = -1;
        else
            cf = (cf + 1) % n;
    }
}
void disC(int n)
{
    if (cf == -1)
        printf("Empty\n");
    else
    {
        int i = cf;
        while (1)
        {
            printf("%d ", q[i]);
            if (i == cr)
                break;
            i = (i + 1) % n;
        }
        printf("\n");
    }
}

int main()
{
    int n = 5;

    enL(10, n);
    enL(20, n);
    enL(30, n);
    disL();
    deL();
    disL();

    enC(1, n);
    enC(2, n);
    enC(3, n);
    disC(n);
    deC(n);
    disC(n);

    return 0;
}