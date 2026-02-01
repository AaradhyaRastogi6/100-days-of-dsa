// Problem: Topological Sort using DFS
// Author: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>

#define N 100

int adj[N][N];
int visited[N];
int stack[N];
int top = -1;
int V;

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// DFS
void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    // 🔥 IMPORTANT: push AFTER visiting children
    push(node);
}

// Topological Sort
void topoSort() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print in reverse stack order
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Driver
int main() {
    int E;
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed
    }

    topoSort();

    return 0;
}