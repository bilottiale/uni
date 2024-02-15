// e2 prende in ingresso un array (aLen, a) e un valore intero positivo val
// e2 é una funzione involucro che chiama una funzione ricorsiva e2R.

// Scrivere inoltre una funzione e2R con le seguenti caratteristiche:
// e2R esegue una ricorsione dicotomica sugli elementi di a[]
// e2R restituisce la somma di tutti gli elementi di a[] il cui valore è compreso tra -val e +val, estremi inclusi.
// Se non ci sono elementi nell'array a[], e2R restituisce 0.


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int e2R(const size_t aLen, const int a[], const int val)
{
    if (aLen == 0){
        return 0;
    }
    else if (aLen == 1){
        if (a[0] <= val && a[0] >= -val){
            return a[0];
        }
        else {
            return 0;
        }
    }
    else {
        int mid = aLen / 2;
        int left = e2R(mid, a, val);
        int right = e2R(aLen - mid, a + mid, val);
        return left + right;
    }
}

int e2(const size_t aLen, const int a[], const int val) {
    return e2R(aLen, a, val);
}

int main(void){
    const size_t aLen = 3;
    const int a[3] = {-1,7,-20};
    printf("%d\n", e2(aLen, a, 10));
}