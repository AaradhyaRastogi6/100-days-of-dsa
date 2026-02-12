#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[m][n];

    // Read matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Condition 1: Must be square
    if (m != n) {
        printf("NO");
        return 0;
    }

    // Check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                printf("NO");
                return 0;
            }
        }
    }

    printf("YES");
    return 0;
}