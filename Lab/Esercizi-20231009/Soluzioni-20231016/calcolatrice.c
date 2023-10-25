// Scrivere un programma selezione_operazioni.c che:
// Chiede all’utente di inserire tre numeri interi x1, x2 e x3.

// Stampa il seguente testo:
// “Scrivi 1 per calcolare la somma.”
// “Scrivi 2 per calcolare il prodotto.”
// “Scrivi 3 per calcolare la media.”

// Chiede all’utente di inserire un numero (tra 1, 2 o 3) corrispondente ad un’operazione.

// Se l'operazione selezionata non è tra quelle proposte, deve essere stampato a video un messaggio di errore appropriato.

// Altrimenti effettua l’operazione selezionata sugli interi x1, x2 e x3, e visualizza il risultato ottenuto.

#include <stdio.h>

int main(void) {
    int x1, x2, x3;
    printf("Inserisci tre numeri interi: ");
    scanf("%d%d%d", &x1, &x2, &x3);

    printf("Scrivi 1 per calcolare la somma.\n");
    printf("Scrivi 2 per calcolare il prodotto.\n");
    printf("Scrivi 3 per calcolare la media.\n");

    int operazione;
    printf("Inserisci un numero tra 1, 2 o 3: ");
    scanf("%d", &operazione);

    if (operazione == 1) {
        printf("La somma e': %d\n", x1 + x2 + x3);
    } else if (operazione == 2) {
        printf("Il prodotto e': %d\n", x1 * x2 * x3);
    } else if (operazione == 3) {
        printf("La media e': %d\n", (x1 + x2 + x3) / 3);
    } else {
        printf("Errore: l'operazione selezionata non e' valida\n");
    }

    return 0;
}