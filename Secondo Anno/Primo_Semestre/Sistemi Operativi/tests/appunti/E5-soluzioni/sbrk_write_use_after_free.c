/*
 * sbrk_use_after_free.c - esempio di "use after free"
 *
 * Anche in questo esempio si investiga cosa succede
 * ad usare la mamoria liberata. A differenza del
 * sorgente sbrk_use_after_free.c, qui si forza
 * l'allocazione di un frame fisico (tramite la
 * scrittura della solita lettera 'A' otto byte dopo
 * il vecchio indirizzo iniziale dell'heap) prima della
 * deallocazione della memoria.
 * Se si scrive nuovamente la lettera 'A' nella stessa
 * cella dopo la deallocazione, si ottiene un segmentation
 * fault? 
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

	/*
	 * Si scriva il valore 65 ('A') ad otto byte di distanza dall'indirizzo
	 * iniziale. Questa scrittura forza l'allocazione di un frame fisico.
	 */
	*((char *)addr + 8) = 65;

	/* Si stampi il valore della cella modificata */
	printf("Carattere: %c\n", *((char *)addr + 8));

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

	exit(EXIT_SUCCESS);
}
