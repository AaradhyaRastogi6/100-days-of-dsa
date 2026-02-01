/*
Problem: Priority Queue using Array
Name: Aditya Gautam
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int arr[MAX];
int size = 0;

/* Insert element */
void insert(int x)
{
    if(size == MAX)
        return;

    arr[size++] = x;
}

/* Delete highest priority (smallest element) */
int delete()
{
    if(size == 0)
        return -1;

    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(arr[i] < arr[minIndex])
            minIndex = i;
    }

    int deleted = arr[minIndex];

    for(int i = minIndex; i < size - 1; i++)
    {
        arr[i] = arr[i+1];
    }

    size--;

    return deleted;
}

/* Peek highest priority element */
int peek()
{
    if(size == 0)
        return -1;

    int min = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }

    return min;
}

int main()
{
    int n;
    scanf("%d", &n);

    char op[10];
    int x;

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0)
        {
            printf("%d\n", delete());
        }
        else if(strcmp(op, "peek") == 0)
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}