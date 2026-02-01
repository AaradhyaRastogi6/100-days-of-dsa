// Problem: Cycle Detection in Undirected Graph (DFS)
// Name: Aditya Gautam

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency Matrix
bool visited[MAX];

// DFS function
bool dfs(int node, int parent, int V) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) { // If edge exists
            if (!visited[i]) {
                if (dfs(i, node, V))
                    return true;
            }
            else if (i != parent) {
                return true; // Cycle found
            }
        }
    }
    return false;
}

// Function to check cycle
bool hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, V))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d", &V); // Number of vertices
    scanf("%d", &E); // Number of edges

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    if (hasCycle(V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}