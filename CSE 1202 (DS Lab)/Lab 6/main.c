// 4

#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c)
{
    if (top < 100 - 1)
        stack[++top] = c;
}
char pop() { return (top >= 0) ? stack[top--] : '\0'; }

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

void ItoP(char infix[])
{
    char post[100];
    int i = 0, k = 0;

    for (; infix[i]; i++)
    {
        if (isalnum(infix[i]))
            post[k++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
                post[k++] = pop();
            pop();
        }
        else
        {
            while (top != -1 && prec(stack[top]) >= prec(infix[i]))
                post[k++] = pop();
            push(infix[i]);
        }
    }

    while (top != -1)
        post[k++] = pop();

    post[k] = '\0';
    printf("Postfix Expression: %s\n", post);
}

int main()
{
    char infix[100];
    printf("Enter an infix expression: ");
    fgets(infix, 100, stdin);
    ItoP(infix);
    return 0;
}

