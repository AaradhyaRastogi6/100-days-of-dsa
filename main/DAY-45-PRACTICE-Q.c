// Problem: Height of Binary Tree
// Name: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->left = t->right = NULL;
    return t;
}

// Recursive height
int height(struct Node* root) {
    if (root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    int n, i = 1;
    scanf("%d", &n);

    int a[n];
    for (int j = 0; j < n; j++) scanf("%d", &a[j]);

    if (a[0] == -1) { printf("0"); return 0; }

    struct Node* root = newNode(a[0]);
    struct Node* q[100];
    int f = 0, r = 0;
    q[r++] = root;

    while (i < n) {
        struct Node* cur = q[f++];

        if (a[i] != -1) {
            cur->left = newNode(a[i]);
            q[r++] = cur->left;
        }
        i++;

        if (i < n && a[i] != -1) {
            cur->right = newNode(a[i]);
            q[r++] = cur->right;
        }
        i++;
    }

    printf("%d", height(root));
    return 0;
}