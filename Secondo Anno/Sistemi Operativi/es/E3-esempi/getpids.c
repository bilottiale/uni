/*
 */
#include <stdio.h>	/* printf() */
#include <unistd.h>	/* fork(), pid_t, sleep() */
#include <stdlib.h>	/* exit() */
#include <errno.h>	/* errno, perror() */
#include <sys/types.h>	/* pid_t */
#include <unistd.h>	/* getpid(), getppid() */

int main(void) {
	pid_t pid = fork();

	/* sono il processo figlio? */
	if (pid == 0) {

		printf("figlio: getpid() = %d\n", getpid());
		printf("figlio: getppid() = %d\n", getppid());
	} else if (pid > 0) { /* sono il processo padre? */ 

		printf("padre: getpid() = %d\n", getpid());
	} else { /* si è verificato un errore */

		/* stampiamo il codice dell'errore */
		printf("errno = %d\n", errno);

		/* stampiamo un messaggio d'errore */
		perror("fork()");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
