/*
Problem: Construct Binary Tree from Level Order and Print Inorder
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left,*right;
}Node;

Node* createNode(int v){
    Node* n=malloc(sizeof(Node));
    n->val=v;
    n->left=n->right=NULL;
    return n;
}

Node* buildTree(int arr[],int n){

    if(n==0 || arr[0]==-1) return NULL;

    Node* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i]==-1) nodes[i]=NULL;
        else nodes[i]=createNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i]){
            int l=2*i+1,r=2*i+2;
            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }

    return nodes[0];
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

int main(){

    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    Node* root=buildTree(arr,n);

    inorder(root);

    return 0;
}