/*
Problem: Queue using Linked List
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *front=NULL,*rear=NULL;

/* Enqueue operation */
void enqueue(int x){
    Node* temp=malloc(sizeof(Node));
    temp->data=x;
    temp->next=NULL;

    if(rear==NULL){
        front=rear=temp;
        return;
    }

    rear->next=temp;
    rear=temp;
}

/* Dequeue operation */
int dequeue(){
    if(front==NULL)
        return -1;

    Node* temp=front;
    int val=temp->data;

    front=front->next;

    if(front==NULL)
        rear=NULL;

    free(temp);
    return val;
}

int main(){

    int n,x;
    char op[10];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s",op);

        if(strcmp(op,"enqueue")==0){
            scanf("%d",&x);
            enqueue(x);
        }
        else if(strcmp(op,"dequeue")==0){
            printf("%d\n",dequeue());
        }
    }

    return 0;
}