#include <sys/types.h>	/* mode_t */
#include <fcntl.h>	/* S_IRUSR, ... */
#include <errno.h>	/* errno, perror() */
#include <unistd.h>	/* read(), stat(), lseek() */
#include <stdlib.h>	/* exit() */
#include <sys/stat.h>	/* fstat() */
#include <stdio.h>	/* printf() */

int main(int argc, char *argv[]) {

	const char file_to_read[] = "file.txt";
	char byte;
	int ret, fd, flags;
	ssize_t ret_bytes;
	mode_t mode;
	struct stat sb;
	off_t offset;

	/* apriamo il file in lettura */
	flags = O_CREAT | O_RDONLY;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if ((fd = open(file_to_read, flags, mode)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	/*
	 * Riposizioniamo l'offset a metà del file.
	 * Primo passo: otteniamo la lunghezza del file.
	 * Secondo passo: ci posizioniamo a metà della
	 * lunghezza partendo dall'inizio (SEEK_SET).
	 */

	/*
	 * Otteniamo la lunghezza del file. Usiamo una
	 * variante di stat(), ovvero fstat(), che
	 * identifica il file tramite il suo descrittore
	 * (e non il percorso).
	 */

	if ((ret = fstat(fd, &sb)) == -1) {
		perror("stat");
		exit(EXIT_FAILURE);
	}

	/* Riposizioniamo l'offset del file al penultimo byte */
	if ((offset = lseek(fd, (off_t) -2, SEEK_END)) == -1) {
		perror("lseek");
		exit(EXIT_FAILURE);
	}

	/* leggiamo il buffer in un colpo solo */
	ret_bytes = read(fd, (void *)&byte, sizeof(char));
	if (ret_bytes != sizeof(char)) {
		perror("read: non sono riuscito a leggere un char");
		exit(EXIT_FAILURE);
	} 

	if ((close(fd) == -1)) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	printf("Carattere letto: %c\n", byte);

	exit(EXIT_SUCCESS);
}
