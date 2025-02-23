/*
 * mmap_anon_offarea.c - esempio di scrittura fuori area
 *
 * Si crea una mappatura anonima di quattro byte
 * e si prova a scrivere il carattere 'A' al di
 * fuori di essa, a 32 byte dall'indirizzo iniziale.
 */

#include <stdio.h> /* perror() */
#include <stdlib.h> /* exit() */
#include <sys/mman.h> /* mmap(), munmap() */

int main(void) {

	int *addr;

	/*
	 * Creazione di una mappa di memoria via mmap().
	 *
	 * Parametri
	 * o addr:   l'indirizzo lineare della mappa
	 *           (NULL -> lo decide il kernel)
	 * o len:    la lunghezza della mappa
	 *           (4 byte)
	 * o prot:   i flag di protezione
	 *           (PROT_READ | PROT_WRITE -> lettura e
	 *           scrittura)
	 * o flags:  il tipo di mappatura
	 *           (MAP_PRIVATE | MAP_ANONYMOUS
	 *           mappa privata al processo e non
	 *           associata ad un file)
	 * o fildes: il descrittore del file
	 *           (-1 in caso di mappatura anonima)
	 * o off:    l'offset del file a partire dal
	 *           quale inizia la mappatura
	 *           (0 nell'esempio in questione)
	 */
	addr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, -1 , 0);
	if (addr == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}

	/* Scrittura di un valore nella mappa */
	*((char *)(addr + 32)) = 65;

	/* Stampa del valore appena scritto */
	printf("Carattere: %c\n", *((char *)(addr + 32)));

	/* Distruzione della mappatura */
	munmap(addr, sizeof(int));

	exit(EXIT_SUCCESS);
}
