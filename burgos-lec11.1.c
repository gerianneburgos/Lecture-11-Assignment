#include <stdio.h>             // includes the standard input/output library for console I/O
#include <stdbool.h>           // includes the header file for the bool type and true/false constants
#include <ctype.h>             // includes the header file for character type functions

void scan_word(int occurrences[26]) {
    char c;                     // declares a character variable to store each character read from input
    while ((c = getchar()) != '\n' && c != EOF) {   // reads characters until a newline or end of file is encountered
        if (isalpha(c)) {       // checks if the character is an alphabetic letter
            occurrences[tolower(c) - 'a']++;   // converts the character to lowercase and update the corresponding array element to track the letter occurrences
        }
    }
}

bool is_anagram(int occurrences1[26], int occurrences2[26]) {
    for (int i = 0; i < 26; i++) {    // iterates through each element of the arrays
        if (occurrences1[i] != occurrences2[i]) {   // checks if any corresponding elements are different, then the words are not anagrams
            return false;
        }
    }
    return true;     // indicates that the elements are the same, then the words are anagrams
}

int main() {
    int occurrences1[26] = {0};     // arrays to store the letter occurrences of each word, initialized with zeros
    int occurrences2[26] = {0};

    printf("Enter first word: ");   // prompts the user to enter the first word
    scan_word(occurrences1);        // scans the first word and update the occurrences array

    printf("Enter second word: ");  // prompts the user to enter the second word
    scan_word(occurrences2);        // scans the second word and update the occurrences array

    if (is_anagram(occurrences1, occurrences2)) {    // checks if the words are anagrams by comparing the occurrences arrays
        printf("The words are anagrams.\n"); // prints if the words are anagrams
    } else {
        printf("The words are not anagrams.\n"); // prints if otherwise
    }

    return 0;
}
