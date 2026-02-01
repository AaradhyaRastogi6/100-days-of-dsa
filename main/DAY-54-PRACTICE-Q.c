#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

// Queue for BFS
typedef struct {
    Node* arr[2000];
    int front, rear;
} Queue;

void enqueue(Queue* q, Node* node) {
    q->arr[q->rear++] = node;
}
Node* dequeue(Queue* q) {
    return q->arr[q->front++];
}
bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Build tree from level-order input
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node* root = (Node*)malloc(sizeof(Node));
    root->val = arr[0]; root->left = root->right = NULL;
    
    Queue q = {0};
    enqueue(&q, root);
    int i = 1;
    
    while (!isEmpty(&q) && i < n) {
        Node* curr = dequeue(&q);
        if (arr[i] != -1) {
            curr->left = (Node*)malloc(sizeof(Node));
            curr->left->val = arr[i];
            curr->left->left = curr->left->right = NULL;
            enqueue(&q, curr->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = (Node*)malloc(sizeof(Node));
            curr->right->val = arr[i];
            curr->right->left = curr->right->right = NULL;
            enqueue(&q, curr->right);
        }
        i++;
    }
    return root;
}

// Zigzag traversal
void zigzagTraversal(Node* root) {
    if (!root) return;
    Queue q = {0};
    enqueue(&q, root);
    bool leftToRight = true;
    
    while (!isEmpty(&q)) {
        int size = q.rear - q.front;
        int level[size];
        
        for (int i = 0; i < size; i++) {
            Node* node = dequeue(&q);
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val;
            
            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }
        
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }
        leftToRight = !leftToRight;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    
    Node* root = buildTree(arr, N);
    zigzagTraversal(root);
    return 0;
}