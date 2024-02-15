// Scrivere un programma saluta.c che chieda l'ora all'utente (come numero intero) e stampi a terminale il saluto più appropriato tra: 
// “Buongiorno”
// “Buon pomeriggio”
// “Buonasera”
// “Buonanotte”

// Definite voi quali intervalli usare per decidere il saluto più appropriato.

#include <stdio.h>

int main(void) {
    int ora;
    printf("Inserisci l'ora: ");
    scanf("%d", &ora);

    if ((ora < 0) || (ora > 24)) {
        printf("L'ora inserita non è valida\n");
        return 1;
    }

    if (ora >= 0 && ora < 12) {
        printf("Buongiorno\n");
    } else if (ora >= 12 && ora < 18) {
        printf("Buon pomeriggio\n");
    } else if (ora >= 18 && ora < 24) {
        printf("Buonasera\n");
    } else {
        printf("Buonanotte\n");
    }

    return 0;
}