/* 
   Problem: Construct Binary Tree & Print Postorder
   Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

// -------- TREE NODE --------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// -------- CREATE NODE --------
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// -------- SEARCH INORDER --------
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// -------- BUILD TREE --------
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    // root from preorder
    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = newNode(rootVal);

    // if leaf node
    if (start == end)
        return root;

    // find root in inorder
    int index = findIndex(inorder, start, end, rootVal);

    // build left & right
    root->left = buildTree(preorder, inorder, start, index - 1, preIndex);
    root->right = buildTree(preorder, inorder, index + 1, end, preIndex);

    return root;
}

// -------- POSTORDER PRINT --------
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// -------- MAIN --------
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    // output
    postorder(root);

    return 0;
}