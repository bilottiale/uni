#include <stdio.h>
#include <stdbool.h>

// la dimensione massima della sequenza letta da standard input
#define MAX_N  20

int main(void) {
	// leggi la lunghezza della sequenza
	size_t N;
	scanf("%zu", &N);

	if (N == 0) {
		printf("Vuoto.\n");
	}else if(N > MAX_N || N < 0){
        printf("Errore: numero di elementi non valido.\n");
    }
	else {
        // leggi la sequenza di N elementi
    	int arr[N];
    	for (size_t i=0; i<N; i++) {
    	    scanf("%d", &arr[i]);
    	}

		// cerca il minimo
		int min = arr[0];
		for (size_t i=1; i<N; i++) {
			if (arr[i] < min)
				min = arr[i];
		}

		// calcola la somma degli elementi che sono 
		// maggiori o uguali al quadrato del minimo
		int somma = 0;
		for (size_t i=0; i<N; i++) {
			if (arr[i] >= min*min)
				somma += arr[i];
		}
		printf("%d\n", somma);
	}
}