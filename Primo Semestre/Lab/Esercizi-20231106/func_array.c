// Scrivere un programma che legge due array da standard input,
// stampa i risultati della funzione conta_univoci chiamato sia sul primo che e sul secondo array,
// poi stampa, su di una nuova riga, gli elementi ripetuti (usando la funzione stampa_elementi_ripetuti).

// 1.
// Scrivere una funzione leggi_array che legge da standard input un numero naturale
// N (0 ≤ N ≤ 20) seguito da N numeri interi, e scrive questi numeri in un array (ricevuto in input).
// 2.
// Scrivere una funzione conta_univoci che, dato un array
// calcola e ritorna il numero di elementi che compaiono una sola volta all'interno dell'array.
// 3.
// Scrivere una funzione stampa_elementi_ripetuti che prende in ingresso due array e stampa (su di una riga)
// tutti gli elementi del primo array che appaiono anche nel secondo array.

// Se lo stesso elemento appare più volte nel primo array (e si trova nel secondo array)
// allora viene stampato più volte.

#include <stdio.h>
#include <stdbool.h>

#define N_MAX 20

void leggi_array(int array[], int *n)
{
    scanf("%d", n);
    for(int i = 0; i < *n; i++)
    {
        scanf("%d", &array[i]);
    }
}

void conta_univoci(int array[], int n){
    int univoci = 0;
    for (int i = 0; i < n; i++)
    {
        bool is_unique = true;
        for (int j = 0; j < n; j++)
        {
            if (i != j && array[i] == array[j])
            {
                is_unique = false;
            }
        }
        if (is_unique)
        {
            univoci++;
        }
    }
    printf("%d ", univoci);
}

void stampa_elementi_ripetuti(int array1[], int array2[], int n1, int n2)
{
    for (int i = 0; i < n1; i++)
    {
        int j = 0;
        while (j < n2 && array1[i] != array2[j])
        {
            j++;
        }
        if (j < n2)
        {
            printf("%d ", array1[i]);
        }
    }
}

int main(void)
{
    int n1, n2;
    int array1[N_MAX], array2[N_MAX];
    leggi_array(array1, &n1);
    leggi_array(array2, &n2);

    conta_univoci(array1, n1);
    conta_univoci(array2, n2);

    printf("\n");
    stampa_elementi_ripetuti(array1, array2, n1, n2);
}