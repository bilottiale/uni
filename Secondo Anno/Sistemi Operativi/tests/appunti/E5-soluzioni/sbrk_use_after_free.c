/*
 * sbrk_use_after_free.c - esempio di "use after free"
 *
 * In questo esempio si investiga cosa succede
 * ad usare la mamoria liberata.
 * Si allocano e si liberano immediatemente
 * 16 byte. Successivamente si scrive una 'A'
 * otto byte dopo il vecchio indirizzo iniziale
 * dell'heap.
 */

#include <stdio.h> /* perror() */
#include <stdlib.h> /* exit() */
#include <unistd.h> /* brk(), sbrk() */

int main(void) {
	const intptr_t increment = 16;
	void *addr;

	/*
	 * Per ottenere il valore attuale del program break è sufficiente
	 * invocare sbrk() con il valore "0" come parametro. Un incremento
	 * nullo non ha alcun effetto sul valore del program break.
	 */
	if ((addr = sbrk(0)) == (void *)-1) {
		perror("sbrk(): old");
		exit(EXIT_FAILURE);
	}

	/* Allocazione: aumento del program break di 16 byte */
	if (sbrk(increment) == (void *)-1) {
		perror("sbrk(): increment");
		exit(EXIT_FAILURE);
	}

	/* Dellocazione: decremento del program break di 16 byte */
	if (brk(addr) == -1) {
		perror("brk(): decrement");
		exit(EXIT_FAILURE);
	}

	/*
	 * Si scriva il valore 65 ('A') ad otto
	 * byte di distanza dall'indirizzo iniziale
	 */
	*((char *)addr + 8) = 65;

	/* Si stampi il valore della cella modificata */
	printf("Carattere: %c\n", *((char *)addr + 8));

	exit(EXIT_SUCCESS);
}
