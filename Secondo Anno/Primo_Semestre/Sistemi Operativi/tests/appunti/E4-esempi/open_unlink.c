/*
 * open_unlink.c - apertura e cancellazione di un file
 *
 * Si apre si cancella un file. Questo programma
 * è usato insieme ad open_sleep per mostrare cosa
 * succede se un file usato da più processi è cancellato.
 */
#include <sys/types.h>	/* mode_t */
#include <fcntl.h>	/* S_IRUSR, ... */
#include <unistd.h>	/* unlink() */
#include <errno.h>	/* errno */
#include <stdio.h>	/* perror() */
#include <stdlib.h>	/* exit() */

int main(int argc, char *argv[]) {

	const char file_to_unlink[] = "file-condiviso.txt";
	int ret, fd, flags;
	mode_t mode;

	/* si apre il file in lettura */
	flags = O_CREAT | O_RDONLY;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	if ((fd = open(file_to_unlink, flags, mode)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	/* si rimuove il link hard */
	if ((ret = unlink(file_to_unlink)) == -1) {
		perror("unlink");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
