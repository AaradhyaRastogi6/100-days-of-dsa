/*
Name: Aditya Gautam
Problem: Implement push and pop operations on a stack and print remaining elements
*/

#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top >= 0)
        top--;
}

// Display stack from top to bottom
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0)
            printf(" ");
    }
}

int main() {
    int n, m;

    // number of elements to push
    scanf("%d", &n);

    // push elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    // number of pops
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    // print remaining stack
    display();

    return 0;
}