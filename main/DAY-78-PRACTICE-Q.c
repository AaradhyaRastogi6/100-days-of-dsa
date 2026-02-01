// Problem: Minimum Spanning Tree (Prim's Algorithm)
// Name: Aditya Gautam

#include <stdio.h>
#include <limits.h>

#define MAX 1000

int graph[MAX][MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize graph with large values
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int key[MAX];
    int visited[MAX];

    // Initialize
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0; // start from node 1

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1;
        int min = INT_MAX;

        // Pick minimum key node
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // Update neighbors
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}