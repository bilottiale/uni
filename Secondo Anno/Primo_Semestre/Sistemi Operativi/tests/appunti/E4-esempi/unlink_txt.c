/*
 * unlink_txt.c - rimozione di un link hard 
 *
 * Si invoca la chiamata di sistema unlink()
 * su di un file esistente, rimuovendo pertanto
 * un link hard.
 */
#include <sys/types.h>	/* mode_t */
#include <unistd.h>	/* unlink() */
#include <errno.h>	/* errno */
#include <stdio.h>	/* perror() */
#include <stdlib.h>	/* exit() */

int main(int argc, char *argv[]) {

	const char hard_link[] = "hard-link-a-file-esistente.txt";
	int ret;

	/* rimuoviamo il link hard */
	if ((ret = unlink(hard_link)) == -1) {
		perror("unlink");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);

}
