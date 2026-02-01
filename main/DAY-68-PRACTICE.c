// Problem: Topological Sort using Kahn's Algorithm (BFS)
// Name: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    printf("Enter edges (u v) meaning u -> v:\n");
    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Queue
    int queue[MAX], front = 0, rear = 0;

    // Push nodes with indegree 0
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int topo[MAX], index = 0;

    while(front < rear) {
        int node = queue[front++];
        topo[index++] = node;

        for(int i = 0; i < V; i++) {
            if(adj[node][i]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Check for cycle
    if(index != V) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for(int i = 0; i < V; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}