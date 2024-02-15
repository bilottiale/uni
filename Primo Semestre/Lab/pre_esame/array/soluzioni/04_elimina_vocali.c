// Scrivi un programma che legge una parola da standard input (lunghezza massima 50 caratteri) 
// e chiama una funzione elimina_vocali, che si occupa di trasformare la stringa eliminando 
// tutti i caratteri che corrispondono alle lettere vocali.

// Stampare il risultato.

#include <stdio.h>
#include <stdbool.h>

#define MAX_STR 50

// restituisce true se il carattere ch è una vocale
bool is_vowel(char ch) {
    const int NUM_VOWELS = 10;
    const char vowels[NUM_VOWELS] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    bool is_v = false;

    for (size_t i=0; i<NUM_VOWELS && !is_v; i++) {
        if (ch == vowels[i])
            is_v = true;
    }
    return is_v;
}

void elimina_vocali(char* pStr) {
    char *pSrc = pStr, *pDst = pStr;
    while (*pSrc != '\0') {
        if (!is_vowel(*pSrc)) {
            *pDst = *pSrc;
            pDst++;
        }
        pSrc++;
    }
    *pDst = '\0';
}

int main(void) {
    char string[MAX_STR + 1];
    scanf("%50s", string);
    
    elimina_vocali(string);
    printf("%s\n", string);
}
