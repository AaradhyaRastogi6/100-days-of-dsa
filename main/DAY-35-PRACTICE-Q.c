/*
Name: Aditya Gautam
Problem: Queue Using Array
*/

#include <stdio.h>

int queue[100];
int front = 0;
int rear = -1;

int main()
{
    int n, i, value;

    // number of elements
    scanf("%d", &n);

    // enqueue elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        rear = rear + 1;
        queue[rear] = value;
    }

    // display queue
    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}