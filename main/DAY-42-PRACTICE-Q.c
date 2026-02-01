/*
Problem: Reverse a Queue using Stack
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *queue = (int*)malloc(n * sizeof(int));
    int *stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    // Read queue elements
    for(int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    // Move queue elements to stack
    for(int i = 0; i < n; i++)
        stack[++top] = queue[i];

    // Move stack elements back to queue (reversing)
    for(int i = 0; i < n; i++)
        queue[i] = stack[top--];

    // Print reversed queue
    for(int i = 0; i < n; i++)
        printf("%d ", queue[i]);

    free(queue);
    free(stack);

    return 0;
}