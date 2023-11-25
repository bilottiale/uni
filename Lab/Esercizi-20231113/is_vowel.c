#include <stdio.h>
#include <stdbool.h>

// ritorna true se il carattere ch è una vocale
#define NUM_VOWELS 10
bool is_vowel(char ch) {
    const char vowels[NUM_VOWELS] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    bool is_v = false;
    for (size_t i=0; i<NUM_VOWELS && !is_v; i++) {
        if (ch == vowels[i])
            is_v = true;
    }
    return is_v;
}

#define MAX_CHAR 50
int main(void) {
    // COMPLETARE
    char str[MAX_CHAR+1];
    printf("Inserisci una stringa: ");
    scanf("%s", str);
    int i = 0;
    while (str[i] != '\0') {
        if (is_vowel(str[i]))
            printf("%c", str[i]);
        i++;
    }
    printf("\n");
}
