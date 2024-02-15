// Scrivere una funzione e2 con le seguenti caratteristiche:

// e2 prende in ingresso un array (aLen, a) e un valore intero positivo val
// e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
// Scrivere inoltre una funzione e2R con le seguenti caratteristiche:
// e2R esegue una ricorsione dicotomica sugli elementi di a[]
// e2R ritorna la somma di tutti gli elementi di a[] il cui valore è compreso tra -val e +val, estremi inclusi.
// Se non ci sono elementi nell'array a[], e2R ritorna 0.

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int e2R(const size_t aLen, const int a[], const int val, int n)
{
    if (n == aLen)
        return 0;
    if (a[n] >= -val && a[n] <= val)
        return a[n] + e2R(aLen, a, val, n + 1);
    return e2R(aLen, a, val, n + 1);
}

int e2(const size_t aLen, const int a[], const int val) {
    int sum = 0;
    sum = e2R(aLen, a, val, 0);
    return sum;
}