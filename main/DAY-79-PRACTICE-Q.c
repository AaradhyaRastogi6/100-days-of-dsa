// Problem: Dijkstra's Algorithm
// Name: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Adjacency list
typedef struct {
    int v, w;
} Edge;

Edge adj[MAX][MAX];
int adjSize[MAX];

// Min heap
typedef struct {
    int node, dist;
} HeapNode;

HeapNode heap[MAX * MAX];
int heapSize = 0;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void push(HeapNode val) {
    heap[++heapSize] = val;
    int i = heapSize;

    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

// Heapify down
HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int left = 2*i, right = 2*i+1, smallest = i;

        if (left <= heapSize && heap[left].dist < heap[smallest].dist)
            smallest = left;

        if (right <= heapSize && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }

    return top;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 1; i <= n; i++) {
        adjSize[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u][adjSize[u]].v = v;
        adj[u][adjSize[u]].w = w;
        adjSize[u]++;

        adj[v][adjSize[v]].v = u; // undirected
        adj[v][adjSize[v]].w = w;
        adjSize[v]++;
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dist[source] = 0;

    push((HeapNode){source, 0});

    while (heapSize > 0) {
        HeapNode curr = pop();
        int u = curr.node;

        if (curr.dist > dist[u]) continue;

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i].v;
            int w = adj[u][i].w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push((HeapNode){v, dist[v]});
            }
        }
    }

    // Output
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}