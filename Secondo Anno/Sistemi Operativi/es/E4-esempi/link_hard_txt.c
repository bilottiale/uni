/*
 * link_hard_txt.c - creazione di un link hard 
 *
 * Si invoca la chiamata di sistema link()
 * su di un file esistente, creando pertanto
 * un link hard.
 */
#include <sys/types.h>	/* mode_t */
#include <unistd.h>	/* link() */
#include <errno.h>	/* errno */
#include <stdio.h>	/* perror() */
#include <stdlib.h>	/* exit() */

int main(int argc, char *argv[]) {

	const char dest_filename[] = "file-esistente.txt";
	const char hard_link[] = "hard-link-a-file-esistente.txt";
	int ret;

	/*
	 * Creiamo il link hard. Attenzione: il primo
	 * parametro è sempre il nome del file già
	 * esistente. Il secondo parametro è il nome
	 * del link.
	 */
	if ((ret = link(dest_filename, hard_link)) == -1) {
		perror("link");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);

}
