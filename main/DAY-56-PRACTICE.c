/* 
   Problem: Symmetric Binary Tree
   Name: Aditya Gautam
    */

#include <stdio.h>
#include <stdlib.h>

// -------- NODE --------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// -------- CREATE NODE --------
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// -------- BUILD TREE --------
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct Node* curr = queue[front++];

        // left
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // right
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// -------- MIRROR CHECK --------
int isMirror(struct Node* left, struct Node* right) {
    if (!left && !right) return 1;
    if (!left || !right) return 0;

    if (left->data != right->data) return 0;

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// -------- MAIN CHECK --------
int isSymmetric(struct Node* root) {
    if (!root) return 1;
    return isMirror(root->left, root->right);
}

// -------- MAIN --------
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    if (isSymmetric(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}