/*
 * open_write_sleep.c - apertura di un file, scrittura e attesa
 *
 * Si apre un file, ci si scrive dentro e si attende
 * in un ciclo continuo.
 * Questo programma è usato insieme ad open_unlink per
 * mostrare cosa succede se un file usato da più processi
 * è cancellato.
 */
#include <sys/types.h>	/* mode_t */
#include <fcntl.h>	/* S_IRUSR, ... */
#include <unistd.h>	/*  write(), sleep() */
#include <errno.h>	/* errno */
#include <stdio.h>	/* perror() */
#include <stdlib.h>	/* exit() */
#include <stdio.h>	/* printf() */

#define BUFSIZE 1024 * 10 * 10
#define SLEEP_INTVL 1

int main(int argc, char *argv[]) {

	const char file_to_write[] = "file-condiviso.txt";
	char buffer[BUFSIZE];
	int fd, flags;
	ssize_t ret;
	mode_t mode;

	/* si apre il file in scrittura */
	flags = O_CREAT | O_WRONLY;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	if ((fd = open(file_to_write, flags, mode)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	/* ciclo infinito di attesa e scrittura */
	while (1) {
		ret = write(fd, (void *)buffer, sizeof(buffer));
		if (ret != sizeof(buffer)) {
			perror("write: non sono riuscito a scrivere il buffer");
			exit(EXIT_FAILURE);
		} 

		/* si informa l'utente della scrittura */
		printf("Scrittura di %zd byte completata\n", ret);

		/* si attende per un po' */
		sleep(SLEEP_INTVL);
	}

	exit(EXIT_SUCCESS);
}
