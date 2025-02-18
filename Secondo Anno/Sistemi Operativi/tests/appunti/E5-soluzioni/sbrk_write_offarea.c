/*
 * sbrk.c - esempio d'uso dell'istruzione sbrk()
 *
 * Esempio di prenotazione dinamica basata su heap
 * (16 byte) e di scrittura sulla stessa (carattere
 * 'A' ad otto byte di distanza del vecchio indirizzo
 * iniziale dell'heap).
 * L'esercizio si conclude con un tentativo di scrittura
 * fuori area (a 32 byte di distanza del vecchio
 * indirizzo iniziale dell'heap).
 */

#include <stdio.h> /* perror() */
#include <stdlib.h> /* exit() */
#include <unistd.h> /* sbrk() */

int main(void) {
	const intptr_t increment = 16;
	void *old_addr, *new_addr;

	/*
	 * Per ottenere il valore attuale del program break è sufficiente
	 * invocare sbrk() con il valore "0" come parametro. Un incremento
	 * nullo non ha alcun effetto sul valore del program break.
	 */
	if ((old_addr = sbrk(0)) == (void *)-1) {
		perror("sbrk(): old");
		exit(EXIT_FAILURE);
	}

	/* Si aumenti il program break di 16 byte */
	if (sbrk(increment) == (void *)-1) {
		perror("sbrk(): increment");
		exit(EXIT_FAILURE);
	}

	/* Si ottenga il nuovo program break */
	if ((new_addr = sbrk(0)) == (void *)-1) {
		perror("sbrk(): new");
		exit(EXIT_FAILURE);
	}

	/*
	 * Si stampi il vecchio ed il nuovo valore e
	 * si verifichi che la differenza sia effettivamente
	 * di 16 byte.
	 */
	printf("Old: %p - New: %p - Diff: %d\n", old_addr, new_addr,
		(int)(new_addr - old_addr));

	/*
	 * Si scriva il valore 65 ('A') ad otto
	 * byte di distanza dall'indirizzo iniziale
	 */
	*((char *)(old_addr + 32)) = 65;

	/* Si stampi il valore della cella modificata */
	printf("Carattere: %c\n", *((char *)old_addr + 8));

	exit(EXIT_SUCCESS);
}
