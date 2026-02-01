// Problem: Level Order Traversal
// Name: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x; n->left = n->right = NULL;
    return n;
}

// Simple queue using array
struct Node* q[1000];
int front = 0, rear = 0;

void enqueue(struct Node* x) { q[rear++] = x; }
struct Node* dequeue() { return q[front++]; }

void levelOrder(struct Node* root) {
    if (!root) return;
    enqueue(root);

    while (front < rear) {
        struct Node* t = dequeue();
        printf("%d ", t->data);

        if (t->left) enqueue(t->left);
        if (t->right) enqueue(t->right);
    }
}

int main() {
    // Hardcoded example (shortest version)
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    levelOrder(root);
    return 0;
}