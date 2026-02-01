// Problem: Height of Binary Tree
// Name: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>

struct Node { int d; struct Node *l, *r; };

struct Node* n(int x){
    struct Node* t = malloc(sizeof(struct Node));
    t->d = x; t->l = t->r = NULL;
    return t;
}

int h(struct Node* r){
    if(!r) return 0;
    int l = h(r->l), rr = h(r->r);
    return (l > rr ? l : rr) + 1;
}

int main(){
    struct Node* r = n(1);
    r->l = n(2); r->r = n(3);
    r->l->l = n(4); r->l->r = n(5);
    r->r->r = n(6);

    printf("%d", h(r));
}