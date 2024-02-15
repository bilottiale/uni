// Scrivere le seguenti funzioni ricorsive su array:
// - leggi_arrayR: funzione ricorsiva che legge n valori da standard input con scanf e li memorizza nell'array a[]
// - somma_arrayR: funzione ricorsiva che calcola la somma dei valori dell'array a[]
// - esiste_val_in_arrayR: funzione ricorsiva che riceve in ingresso 
//   un array (aLen,a[]) ed un valore val, e 
//   restituisce true se val compare tra gli elementi di a[].
// - sottoinsiemeR: funzione ricorsiva che riceve in ingresso 
//   un array (aLen,a[]) ed un array (bLen,b[]), e 
//   restituisce true se ogni elemento di a[] compare nell'array b[]

// Per ciascuna funzione ricorsiva scrivere la corrispondente funzione involucro.

// Il programma deve leggere da standard input due array a[] e b[], 
// stampare su di una sola riga la somma dei valori degli array a[] e b[], ed 
// infine stampare su di una seconda linea un valore booleano (0 o 1) se A è sottoinsieme di B, e 
// se B è sottoinsieme di A.

// INPUT: per ciascun array compare prima il numero di elementi len, seguito dai len valori interi dell'array.
// NOTA: non potete scrivere cicli for/while.
#include <stdio.h>
#include <stdbool.h>

//------------------------------------------------------------------
// Prototipi delle funzioni (solo gli involucri)
//------------------------------------------------------------------

void leggi_array(const size_t aLen, int a[]);
int somma_array(const size_t aLen, int a[]);
bool esiste_val_in_array(const size_t aLen, const int a[], int val);
bool sottoinsieme(const size_t aLen, const int a[], 
			      const size_t bLen, const int b[]);

//------------------------------------------------------------------

int main(void) {
	size_t aLen, bLen;

	scanf("%zu", &aLen);
	int a[aLen];
	leggi_array(aLen, a);

	scanf("%zu", &bLen);
	int b[bLen];
	leggi_array(bLen, b);

	printf("%d %d\n", somma_array(aLen, a), somma_array(bLen, b));

	printf("%d %d\n", 
		   sottoinsieme(aLen, a, bLen, b),
		   sottoinsieme(bLen, b, aLen, a));
}

//------------------------------------------------------------------

void leggi_arrayR(const size_t aLen, int a[], size_t i) {
	if (i==aLen)
		return;
	scanf("%d", &a[i]);
	leggi_arrayR(aLen, a, i+1);
}
void leggi_array(const size_t aLen, int a[]) { 
	leggi_arrayR(aLen, a, 0);
}

//------------------------------------------------------------------

int somma_arrayR(const size_t aLen, int a[], size_t i) {
	if (i==aLen)
		return 0;
	return a[i] + somma_arrayR(aLen, a, i+1);
}
int somma_array(const size_t aLen, int a[]) {
	return somma_arrayR(aLen, a, 0);
}

//------------------------------------------------------------------

bool esiste_val_in_arrayR(const size_t aLen, const int a[], size_t i, int val) {
	if (i==aLen)
		return false;
	return (a[i]==val) || esiste_val_in_arrayR(aLen, a, i+1, val);
}
bool esiste_val_in_array(const size_t aLen, const int a[], int val) {
	return esiste_val_in_arrayR(aLen, a, 0, val);
}

//------------------------------------------------------------------

bool sottoinsiemeR(const size_t aLen, const int a[], 
			       const size_t bLen, const int b[], size_t i)
{
	if (i==aLen)
		return true;
	return esiste_val_in_array(bLen, b, a[i]) && sottoinsiemeR(aLen, a, bLen, b, i+1);
}
bool sottoinsieme(const size_t aLen, const int a[], 
			      const size_t bLen, const int b[])
{
	return sottoinsiemeR(aLen, a, bLen, b, 0);
}

//------------------------------------------------------------------

