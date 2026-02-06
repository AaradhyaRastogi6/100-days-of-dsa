#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0) return 0;

    int write = 1;

    for (int read = 1; read < n; read++) {
        if (arr[read] != arr[read - 1]) {
            arr[write] = arr[read];
            write++;
        }
    }

    for (int i = 0; i < write; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
