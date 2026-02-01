// Problem: 841. Keys and Rooms
// Name: Aditya Gautam

#include <stdbool.h>

// DFS traversal
void dfs(int room, int** rooms, int* roomsColSize, bool* visited) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int next = rooms[room][i];

        if (!visited[next]) {
            dfs(next, rooms, roomsColSize, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];

    // Initialize
    for (int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }

    // Start from room 0
    dfs(0, rooms, roomsColSize, visited);

    // Check if all visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}