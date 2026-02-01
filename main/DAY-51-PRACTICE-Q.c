/*  Problem: Lowest Common Ancestor in BST
  Name   : Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *left, *right;
};

// Create new node
struct node* newNode(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
struct node* insert(struct node* root, int x) {
    if (root == NULL)
        return newNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Find LCA
struct node* findLCA(struct node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // Both values smaller → go left
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    // Both values greater → go right
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    // Split point → LCA found
    return root;
}

int main() {
    struct node* root = NULL;
    int n, x, n1, n2;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter two nodes: ");
    scanf("%d %d", &n1, &n2);

    struct node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("LCA: %d", lca->data);
    else
        printf("LCA not found");

    return 0;
}