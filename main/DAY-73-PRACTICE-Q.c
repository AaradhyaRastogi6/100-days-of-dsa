#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(char *s) {
    int freq[26] = {0};  // Frequency array for lowercase letters
    
    // Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
    
    // Find the first character with frequency 1
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }
    
    return '$';  // If all characters repeat
}

int main() {
    char s[100];
    scanf("%s", s);
    
    char result = firstNonRepeatingChar(s);
    printf("%c\n", result);
    
    return 0;
}
