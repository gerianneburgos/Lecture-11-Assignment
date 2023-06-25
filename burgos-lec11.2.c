#include <stdio.h>
#include <stdbool.h>

void scan_word(char *word, int *occurrences) {
    for (int i = 0; i < 26; i++) {
        occurrences[i] = 0;
    }

    while (*word != '\0') {
        if (*word >= 'a' && *word <= 'z') {
           occurrences[*word - 'a']++;
        }
    
        word++;
    }
}

bool is_anagram(int *occurrences1, int *occurrences2) {

     for (int i = 0; i < 26; i++) {
        if (occurrences1[i] != occurrences2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char word1[100], word2[100];
    int occurrences1[26], occurrences2[26];

    // Scan the first word
    printf("Enter the first word: ");
    scanf("%s", word1);
        scan_word(word1, occurrences1);

    // Scan the second word
    printf("Enter the second word: ");
    scanf("%s", word2);
    scan_word(word2, occurrences2);

    // Check if the two words are anagrams
    if (is_anagram(occurrences1, occurrences2)) {
        printf("The words are anagrams.\n");
    } 
    else {
        printf("The words are not anagrams.\n");
    }
 return 0;
}