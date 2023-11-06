// Scrivere un programma alfabeto.c che crea un array di 27 caratteri.
// - Il programma inizializza con un ciclo for i primi 26 caratteri con le lettere progressive dell’alfabeto dalla ‘A’ fino alla ‘Z’.
// - Inserisce il terminatore della stringa.
// - Stampa la stringa ottenuta con printf.

#include <stdio.h>

int main(void) {
    char alfabeto[27];
    int i;

    for (i = 0; i < 26; i++) {
        alfabeto[i] = 'A' + i;
    }
    alfabeto[i] = '\0';

    printf("%s\n", alfabeto);

    return 0;
}
