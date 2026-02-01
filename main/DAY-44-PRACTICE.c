/*
Problem: Binary Tree Traversals (Inorder Preorder Postorder)
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left,*right;
}Node;

Node* newNode(int v){
    Node* n=malloc(sizeof(Node));
    n->val=v;
    n->left=n->right=NULL;
    return n;
}

void inorder(Node* r){
    if(!r) return;
    inorder(r->left);
    printf("%d ",r->val);
    inorder(r->right);
}

void preorder(Node* r){
    if(!r) return;
    printf("%d ",r->val);
    preorder(r->left);
    preorder(r->right);
}

void postorder(Node* r){
    if(!r) return;
    postorder(r->left);
    postorder(r->right);
    printf("%d ",r->val);
}

int main(){

    int n;
    scanf("%d",&n);

    Node* nodes[n];
    int x;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x==-1) nodes[i]=NULL;
        else nodes[i]=newNode(x);
    }

    for(int i=0;i<n;i++){
        if(nodes[i]){
            int l=2*i+1,r=2*i+2;
            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }

    Node* root=nodes[0];

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);

    return 0;
}