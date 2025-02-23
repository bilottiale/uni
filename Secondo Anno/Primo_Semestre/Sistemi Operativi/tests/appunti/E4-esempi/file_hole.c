/*
 * file_hole.c - creazione di file sparsi
 *
 * Si illustra l'uso della chiamata di sistema
 * lseek() per posizionare la testina di lettura
 * oltre la fine di un file. Successivamente,
 * si scrive sul file alla nuova posizione,
 * creando un file sparso.
 */

#include <sys/types.h>	/* mode_t */
#include <fcntl.h>	/* S_IRUSR, ... */
#include <errno.h>	/* errno, perror() */
#include <unistd.h>	/* read(), lseek(), write() */
#include <stdlib.h>	/* exit() */
#include <stdio.h>	/* printf() */

#define OFFSET	1024 * 1024 * 10	/* 10 MB */

int main(int argc, char *argv[]) {

	const char file_to_read[] = "file-con-hole";
	char byte = 'a';
	int fd, flags;
	ssize_t ret;
	mode_t mode;
	off_t offset;

	/* apriamo il file in lettura e scrittura */
	flags = O_CREAT | O_RDWR;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if ((fd = open(file_to_read, flags, mode)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	/*
	 * Riposizioniamo l'offset oltre la fine
	 * del file. Usiamo il flag SEEK_END.
	 */
	
	/* Riposizioniamo l'offset del file */
	if ((offset = lseek(fd, (off_t) OFFSET, SEEK_END)) == -1) {
		perror("lseek");
		exit(EXIT_FAILURE);
	}

	/* scriviamo un byte alla nuova posizione */
	ret = write(fd, (void *)&byte, sizeof(char));
	if (ret != sizeof(char)) {
		perror("write: non sono riuscito a scrivere un char");
		exit(EXIT_FAILURE);
	} 

	if ((close(fd) == -1)) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
