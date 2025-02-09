/*
 * brk.c - esempio d'uso dell'istruzione brk()
 *
 * La chiamata di sistema brk() consente di impostare
 * il program break ad un indirizzo ben preciso.
 */

#include <stdio.h> /* perror() */
#include <stdlib.h> /* exit() */
#include <unistd.h> /* sbrk(), brk() */

int main(void) {
	const intptr_t increment = 16;
	void *old_addr, *new_addr;

	/*
	 * Per ottenere il valore attuale del program break è sufficiente
	 * invocare sbrk() con il valore "0" come parametro
	 */
	if ((old_addr = sbrk(0)) == (void *)-1) {
		perror("sbrk(): old");
		exit(EXIT_FAILURE);
	}

	/* Si aumenti il program break di 16 byte */
	if (brk(old_addr + increment) == -1) {
		perror("brk(): increment");
		exit(EXIT_FAILURE);
	}

	/* Si memorizzi il nuovo program break */
	if ((new_addr = sbrk(0)) == (void *)-1) {
		perror("sbrk(): new");
		exit(EXIT_FAILURE);
	}

	/*
	 * Si stampi il vecchio ed il nuovo valore e
	 * si verifichi che la differenza sia
	 * effettivamente di 16 byte
	 */
	printf("Old: %p - New: %p - Diff: %d\n", old_addr, new_addr,
		(int)(new_addr - old_addr));

	exit(EXIT_SUCCESS);
}
