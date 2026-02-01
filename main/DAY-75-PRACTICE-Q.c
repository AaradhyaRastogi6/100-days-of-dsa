// Problem: Longest Subarray with Sum Zero
// Name: Aditya Gautam

#include <stdio.h>

#define MAX 1000

int maxLen(int arr[], int n) {
    
    int prefixSum = 0;
    int maxLength = 0;

    // Hash map simulation (prefixSum -> first index)
    int map[20001];   // range handling (-10000 to +10000)
    
    for (int i = 0; i < 20001; i++) {
        map[i] = -2;  // means not visited
    }

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum becomes 0
        if (prefixSum == 0) {
            maxLength = i + 1;
        }

        int key = prefixSum + 10000; // shift for negative index

        // Case 2: first time seen
        if (map[key] == -2) {
            map[key] = i;
        }
        // Case 3: already seen
        else {
            int length = i - map[key];
            if (length > maxLength) {
                maxLength = length;
            }
        }
    }

    return maxLength;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", maxLen(arr, n));

    return 0;
}