/*Problem: Deque (Double-Ended Queue)

NAME : ADITYA GAUTAM */

#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

// check empty
int empty() {
    if (front == -1)
        return 1;
    return 0;
}

// size of deque
int size() {
    if (front == -1)
        return 0;
    return rear - front + 1;
}

// push at front
void push_front(int value) {
    if (front == 0) {
        printf("Deque overflow at front\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }

    deque[front] = value;
}

// push at rear
void push_back(int value) {
    if (rear == MAX - 1) {
        printf("Deque overflow at rear\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
}

// pop from front
void pop_front() {
    if (empty()) {
        printf("Deque underflow\n");
        return;
    }

    printf("Removed from front: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// pop from rear
void pop_back() {
    if (empty()) {
        printf("Deque underflow\n");
        return;
    }

    printf("Removed from rear: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// get front element
void get_front() {
    if (empty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

// get rear element
void get_back() {
    if (empty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

// display deque
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();

    get_front();
    get_back();

    pop_front();
    pop_back();

    display();

    printf("Size of deque: %d\n", size());

    if (empty())
        printf("Deque is empty\n");
    else
        printf("Deque is not empty\n");

    return 0;
}