/*
 * malloc_use_after_free.c - esempio di use-after-free
 *                           con malloc()
 *
 * Si usa la funzione di libreria malloc() per allocare
 * 16B di memoria. Tale memoria dovrebbe essere presa
 * dall'heap. Si verifica questa proprietà.
 * Si scrive il carattere 'A' dentro l'area di memoria
 * (a 5B di distanza dall'indirizzo iniziale) e si
 * libera la memoria allocata.
 * Si stampa il valore dell'heap prima, durante e dopo
 * l'uso dell'area di memoria.
 * Si libera l'area di memoria e si tenta nuovamente
 * la stessa scrittura.
 * Che cosa succede?
 */

#include <stdio.h> /* perror() */
#include <stdlib.h> /* exit(), malloc(), free() */
#include <unistd.h> /* sbrk() */

int main (void)
{
	size_t size;
	char *p;

	/* Si stampa il valore del program break */
	printf("Program break prima di malloc(): %p\n", sbrk(0));

	/*
	 * Si alloca dinamicamente un'area di memoria di 16B.
	 */
	size = sizeof(char) * 16;
	if ((p = (char *)malloc(size)) == NULL) {
		perror("malloc()");
		exit(EXIT_FAILURE);
	}

	/* Si stampa il valore del program break */
	printf("Program break dopo malloc(): %p\n", sbrk(0));

	/* Si stampa l'indirizzo iniziale dell'area prenotata */
	printf("p: %p\n", p);

	/*
	 * Si scrive il carattere 'A' a 5B di
	 * distanza dall'indirizzo iniziale p.
	 */
	*(p + 4) = 'A';
	printf("Contenuto di p + 4: %c\n", *(p + 4));

	/* Si libera l'area di memoria allocata. */
	free(p);

	/* Si stampa il valore del program break */
	printf("Program break dopo free(): %p\n", sbrk(0));

	/*
	 * Si scrive il carattere 'B' a 5B di
	 * distanza dall'indirizzo iniziale p.
	 */
	*(p + 4) = 'B';
	printf("Contenuto di p + 4: %c\n", *(p + 4));

	exit(EXIT_SUCCESS);
}
