/*
 * link_sym_txt.c - creazione di un link simbolico 
 *
 * Si invoca la chiamata di sistema symlink()
 * su di un file esistente, creando pertanto
 * un link simbolico.
 */
#include <sys/types.h>	/* mode_t */
#include <unistd.h>	/* symlink() */
#include <errno.h>	/* errno */
#include <stdio.h>	/* perror() */
#include <stdlib.h>	/* exit() */

int main(int argc, char *argv[]) {

	const char dest_filename[] = "file-esistente.txt";
	const char sym_link[] = "sym-link-a-file-esistente.txt";
	int ret;

	/*
	 * Creiamo il link sym. Attenzione: il primo
	 * parametro è sempre il nome del file già
	 * esistente. Il secondo parametro è il nome
	 * del link.
	 */
	if ((ret = symlink(dest_filename, sym_link)) == -1) {
		perror("symlink");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);

}
