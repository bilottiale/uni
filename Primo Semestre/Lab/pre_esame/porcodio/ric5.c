//e2 prende in ingresso due array: (aLen, a) e (bLen, b)
//e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
//Scrivere una funzione e2R con le seguenti caratteristiche:

//e2R rimuove in place tutte le occorrenze, eccetto la prima, di ogni elemento di a che compare anche in b.
//e2R restituisce la nuova dimensione di a.

#include <stdio.h>
#include <stdbool.h>

// ritorna true se un elemento val esiste in un dato array
void esiste_elemento() { // metodo suggerito da implementare
}

// rimuove tutte le occorrenze di un elemento val in un array,
// partendo da un indice i data in input.
void rimuovi_elementiR(){ // metodo suggerito da implementare
}

void e2R() {
//COMPLETARE
}

int e2(size_t* p_aLen, int a[], const size_t bLen, const int b[]) {
    e2R();
}

int main(void){
    size_t aLen = 4; const size_t bLen = 1;
    int a[4] = {2, 3, 2, 4};
    const int b[1] = {2};
    e2(&aLen, a, bLen, b);
    //int_array_print(aLen, a);
}