// Scrivere un programma che riceve dallo standard input (cioè che legge con scanf) due numeri interi n ed m, 
// e stampa un messaggio a seconda che valga una di queste condizioni:
// - se n è pari e maggiore di m, allora stampa "C1"
// - se n è pari e minore o uguale ad m, allora stampa "C2"
// - se invece n è dispari, procede in questo modo:
//  - se anche m è dispari stampa "C3"
//  - se invece m non é dispari ma è più del doppio di n, allora stampa "C4"
//  - in ogni altro caso, stampa "ALTRO"

#include <stdio.h>

int main(void) {
    // Leggi i dati dallo standard input usando scanf
    int n, m;
    scanf("%d%d", &n, &m);
    
    if (n % 2 == 0) {
        if (n > m)
            puts("C1");
        else
            puts("C2");
    }
    else {
        if (m % 2 == 1) {
            puts("C3");
        }
        else if (m > 2 * n) {
            puts("C4");
        }
        else
            puts("ALTRO");
    }
}