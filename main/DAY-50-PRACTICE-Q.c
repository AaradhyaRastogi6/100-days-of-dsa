/*====================================================
  Problem: BST Search (Full Program)
  Name   : Aditya Gautam
====================================================*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search in BST
int search(struct TreeNode* root, int key) {
    if (root == NULL)
        return 0;

    if (root->val == key)
        return 1;

    if (key < root->val)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    struct TreeNode* root = NULL;
    int n, x, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("Element Found");
    else
        printf("Element Not Found");

    return 0;
}