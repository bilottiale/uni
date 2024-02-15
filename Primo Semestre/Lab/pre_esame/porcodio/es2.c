// Scrivere una funzione e2 con le seguenti caratteristiche:

// e2 prende in ingresso due array: (aLen, a) e (bLen, b)
// e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
// Scrivere inoltre una funzione e2R con le seguenti caratteristiche:

// e2R considera ciascuna coppia di elementi di a e di b nella medesima posizione, fino alla lunghezza massima di entrambi gli array.
// Per ciascuna posizione, e2R calcola il prodotto (se entrambi gli elementi della coppia sono disponibili), oppure il quadrato dell'elemento (se un solo elemento è disponibile, e l'altro array è terminato).
// e2R ritorna la somma dei valori calcolati fino alla lunghezza massima di entrambi gli array.
// Se non ci sono elementi nei due array, e2R ritorna 0.

#include <stdio.h>
#include <stdbool.h>

int e2R(const size_t aLen, const int a[], const size_t bLen, const int b[]) {
    if (aLen == 0 && bLen == 0)
        return 0;
    if (aLen == 0)
        return b[0] * b[0] + e2R(aLen, a, bLen - 1, b + 1);
    if (bLen == 0)
        return a[0] * a[0] + e2R(aLen - 1, a + 1, bLen, b);
    return a[0] * b[0] + e2R(aLen - 1, a + 1, bLen - 1, b + 1);
}

int e2(const size_t aLen, const int a[], const size_t bLen, const int b[]) {
    int val = 0;
    val = e2R(aLen, a, bLen, b);
    return val;
}