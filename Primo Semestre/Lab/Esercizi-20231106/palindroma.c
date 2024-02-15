#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WORD_MAX 50

void palindroma(char word[], char reverse[]) {
    bool is_palindroma = true;

    for (int i = 0; i < strlen(word); i++) {
        reverse[i] = word[strlen(word) - i - 1];
    }

    for (int i = 0; i < strlen(word); i++) {
        if (word[i] != reverse[i]) {
            is_palindroma = false;
        }
    }
    
    if (is_palindroma) {
        printf("PALINDROMA\n");
    } else{
        printf("%s %s", word, reverse);
    }
}

int main() {
    char word[WORD_MAX];
    char reverse[WORD_MAX];
    scanf("%s", word);

    palindroma(word, reverse);
}
