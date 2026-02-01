/*
Problem: Level Order Traversal
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val){
    struct Node* n=malloc(sizeof(struct Node));
    n->data=val; n->left=n->right=NULL;
    return n;
}

struct Node* buildTree(int arr[], int n){
    if(n==0||arr[0]==-1) return NULL;

    struct Node* root=newNode(arr[0]);
    struct Node* q[n];
    int f=0,r=0,i=1;

    q[r++]=root;

    while(i<n){
        struct Node* cur=q[f++];

        if(arr[i]!=-1){
            cur->left=newNode(arr[i]);
            q[r++]=cur->left;
        }
        i++;

        if(i<n && arr[i]!=-1){
            cur->right=newNode(arr[i]);
            q[r++]=cur->right;
        }
        i++;
    }
    return root;
}

void levelOrder(struct Node* root){
    if(!root) return;

    struct Node* q[1000];
    int f=0,r=0;

    q[r++]=root;

    while(f<r){
        int size=r-f;

        while(size--){
            struct Node* cur=q[f++];
            printf("%d ",cur->data);

            if(cur->left) q[r++]=cur->left;
            if(cur->right) q[r++]=cur->right;
        }
    }
}

int main(){
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr,n);
    levelOrder(root);
}