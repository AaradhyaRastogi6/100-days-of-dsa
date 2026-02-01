// Problem Name: First Repeated Character
// Author: Aditya Gautam

#include <stdio.h>
#include <string.h>

char firstRepeatedCharacter(char *s) {
    int seen[26] = {0};  // For 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (seen[index] == 1) {
            return s[i];  // First repeated character
        }

        seen[index] = 1;
    }

    return '\0';  // No repeated character
}

int main() {
    char s[1000];

    // Input
    scanf("%s", s);

    char result = firstRepeatedCharacter(s);

    // Output
    if (result == '\0')
        printf("-1\n");
    else
        printf("%c\n", result);

    return 0;
}