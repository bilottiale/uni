#include <stdio.h>

#define NUM_RISP 20 // risposte al questionario
#define MAX_STARS 6  // le risposte vanno da 1 a 5


int main() {
	// risposte ai questionari
	const int risposte[NUM_RISP] = {
		1, 2, 5, 4, 3,  5, 2, 1, 3, 1, 
		4, 3, 3, 3, 2,  3, 3, 2, 2, 5 
	};

	// calcola le frequenze delle risposte
	int frequenze[MAX_STARS] = {0};
	for (size_t i=0; i<NUM_RISP; i++) {
		// aumenta di uno la frequenza corrispondente alla risposta i-esima
		frequenze[risposte[i]]++;
	}

	// stampa le frequenze
	puts("Stelle  Frequenza");
	for (size_t r=1; r<MAX_STARS; r++) {
		printf("%6zu %10d   ", r, frequenze[r]);
		// stampa un istogramma, con un carattere '#' 
		// per ciascuna risposta al questionario con r stelle
		for (size_t num=0; num<frequenze[r]; num++) {
			putchar('#');
		}
		puts("");
	}

}
