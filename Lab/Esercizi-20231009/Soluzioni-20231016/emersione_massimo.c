// Scrivere un programma che riceve dallo standard input (cioè che legge con scanf) quattro numeri interi x1, x2, x3 e x4, 
// li riordini con opportune operazioni di scambio, 
// e alla fine li ristampi su di un unica linea di testo dal più piccolo al più grande.

// Suggerimento: procedere con una variabile alla volta:
// - partire con x1 e ottenere: x1 ≤ x2, x3, x4
// - a seguito procedere con x2 per ottenere: x2 ≤ x3, x4
// - infine procedere con: x3 ≤ x4

#include <stdio.h>

int main(void) {
    // Leggi i dati dallo standard input usando scanf
    int x1, x2, x3, x4;
    scanf("%d%d%d%d", &x1, &x2, &x3, &x4);
    
    // Scambia per riordinare le variabili, in modo che
    //  x1 <= x2 <= x3 <= x4
    
    // COMPLETARE IL CODICE
    int t;
    if (x1 > x2) { t=x1; x1=x2; x2=t; }
    if (x1 > x3) { t=x1; x1=x3; x3=t; }
    if (x1 > x4) { t=x1; x1=x4; x4=t; }
    if (x2 > x3) { t=x2; x2=x3; x3=t; }
    if (x2 > x4) { t=x2; x2=x4; x4=t; }
    if (x3 > x4) { t=x3; x3=x4; x4=t; }
    
    // Stampa le variabili ordinate
    printf("%d %d %d %d\n", x1, x2, x3, x4);
}