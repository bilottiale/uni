#include <stdio.h>	/* printf() */
#include <unistd.h>	/* fork(), pid_t, sleep() */
#include <stdlib.h>	/* exit() */
#include <errno.h>	/* errno, perror() */

#define SLEEP_INTVL	1

int main(void) {
	pid_t pid = fork();

	/* sono il processo figlio? */
	if (pid == 0) {

		int j;
		for (j = 0; j < 10; j++) {
			printf("figlio: %d\n", j);
			sleep(SLEEP_INTVL);
		}
	} else if (pid > 0) { /* sono il processo padre? */ 

		int i;
		for (i = 0; i < 10; i++)
		{
			printf("padre: %d\n", i);
			sleep(1);
		}
	} else { /* si è verificato un errore */

		/* stampiamo il codice dell'errore */
		printf("errno = %d\n", errno);

		/* stampiamo un messaggio d'errore */
		perror("fork()");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
