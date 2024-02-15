// e2 prende in ingresso un array a[] di dimensione *p_aVal, e due interi min e max
// e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
// Scrivere inoltre una funzione e2R con le seguenti caratteristiche:

// e2R esegue una ricorsione sugli elementi dell'array a[]
// e2R filtra e modifica in-place gli elementi di a[], mantenendo solo gli elementi che sono compresi tra min e max (estremi inclusi)
// alla fine della ricorsione, e2R modifica anche il valore puntato da *p_aVal, scrivendo il numero di elementi rimasti nell'array a[].

#include <stdio.h>
#include <stdbool.h>

void shift_elements(int a[], size_t *p_aVal, size_t index) {
    if (index >= *p_aVal - 1)
        return;

    a[index] = a[index + 1];
    shift_elements(a, p_aVal, index + 1);
}

void e2R(int a[], size_t *p_aVal, const int min, const int max, size_t index, size_t count) {
    if (index >= *p_aVal) {
        *p_aVal = count; // Aggiornamento della dimensione dell'array
        return;
    }

    if (a[index] < min || a[index] > max) {
        // Se l'elemento non è compreso tra min e max, lo rimuoviamo spostando gli elementi successivi
        shift_elements(a, p_aVal, index);
        (*p_aVal)--; // Riduciamo la dimensione dell'array
        e2R(a, p_aVal, min, max, index, count); // Chiamata ricorsiva con lo stesso indice
    } else {
        e2R(a, p_aVal, min, max, index + 1, count + 1); // Chiamata ricorsiva avanzando all'elemento successivo e incrementando il contatore
    }
}

void e2(size_t *p_aVal, int a[], const int min, const int max) {
    e2R(a, p_aVal, min, max, 0, 0); // Chiamata alla funzione ricorsiva e2R con indice iniziale e contatore iniziale a 0
}

int main(void)
{
    size_t aLen = 4;
    int a[4] = {1, 2, 3, 4};
    e2(&aLen, a, 2, 3);
}