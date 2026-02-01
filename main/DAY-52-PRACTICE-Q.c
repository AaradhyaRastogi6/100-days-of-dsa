/*
Problem: Lowest Common Ancestor (Binary Tree)
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

//BUILD TREE
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// FIND NODE POINTER
struct Node* findNode(struct Node* root, int val) {
    if (!root) return NULL;
    if (root->data == val) return root;

    struct Node* left = findNode(root->left, val);
    if (left) return left;

    return findNode(root->right, val);
}

// LCA FUNCTION
struct Node* LCA(struct Node* root, struct Node* p, struct Node* q) {
    if (!root || root == p || root == q)
        return root;

    struct Node* left = LCA(root->left, p, q);
    struct Node* right = LCA(root->right, p, q);

    return (left && right) ? root : (left ? left : right);
}

// MAIN 
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int x, y;
    scanf("%d %d", &x, &y);

    struct Node* root = buildTree(arr, n);

    struct Node* p = findNode(root, x);
    struct Node* q = findNode(root, y);

    struct Node* ans = LCA(root, p, q);

    if (ans)
        printf("%d\n", ans->data);

    return 0;
}