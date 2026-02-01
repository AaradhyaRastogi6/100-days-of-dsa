// Problem: Hash Table using Quadratic Probing
// Name: Aditya Gautam

#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define SIZE 100

int table[SIZE];

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = EMPTY;
}

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash Table Overflow\n");
}

// Search using quadratic probing
void search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
        i++;
    }

    printf("NOT FOUND\n");
}

// Main
int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    init();

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}