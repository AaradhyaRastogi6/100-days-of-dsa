/*
Name: Aditya Gautam
Problem: Convert Infix Expression to Postfix using Stack
*/

#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push function */
void push(char x)
{
    stack[++top] = x;
}

/* Pop function */
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

/* Check precedence */
int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[MAX];
    int i;
    char x;

    printf("Enter infix expression:\n");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        /* If operand → print */
        if (isalnum(exp[i]))
        {
            printf("%c", exp[i]);
        }

        /* If operator */
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i]))
            {
                printf("%c", pop());
            }
            push(exp[i]);
        }
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        printf("%c", pop());
    }

    return 0;
}