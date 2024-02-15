// Scrivere un programma che legge una serie di sequenze di numeri interi positivi terminati dallo zero.
// Per ciascuna sequenza letta, il main deve stampare, su di una linea di testo, i seguenti elementi:

// - la somma degli elementi della sequenza
// - la somma dei quadrati degli elementi della sequenza
// - il massimo degli elementi della sequenza

// Se la sequenza letta non ha elementi (cioè é subito terminata dallo zero), il programma termina.

// SUGGERIMENTO: scrivere una funzione leggi_sequenza, che si occupa di leggere una singola sequenza terminata da 0
// e ritorna al main le tre quantità da stampare. La funzione ritorna true se la sequenza letta non è vuota.

// Scrivere nel main un ciclo che chiama leggi_sequenza() e poi stampa le tre quantità richieste.
// Il ciclo nel main termina quando viene letta la sequenza vuota.

#include <stdio.h>
#include <stdbool.h>

void leggi_sequenza(int *n, int *sum, int *sum_sq, int *max)
{
    *sum = *sum + *n;
    *sum_sq = *sum_sq + (*n * *n);
    if (*n > *max)
    {
        *max = *n;
    }
}

int main(void)
{
    int n = 1;

    while (true)
    {
        int sum = 0;
        int sum_sq = 0;
        int max = 0;

        while (true)
        {
            scanf("%d", &n);
            if (n == 0)
                break;
            leggi_sequenza(&n, &sum, &sum_sq, &max);
        }

        if (sum == 0 && sum_sq == 0 && max == 0)
            break;

        printf("%d %d %d\n", sum, sum_sq, max);
    }
}